#include"linkedlist.h"
static node_t *find_previos_of_node(list_nodes_t *list_obj,node_t*node_obj);


list_nodes_t *create_list(void){

 list_nodes_t*temp = (list_nodes_t*)calloc(1,sizeof(list_nodes_t));
 if(temp)
 {
    return temp;
 }

}

//**************************************
node_t *create_node(void){

    node_t *temp = (node_t*)calloc(1,sizeof(node_t));
    if(temp)
    {    
        printf("Enter data of node: ");
        scanf("%d",&temp->data);
        return temp;
    }


    return NULL;

}

//***************************************
/**
  *this function add node at start of list if empty.
  *and add at end if not emmpty
  *so anywhere inserted node would be lastnode 
  */

status_t append_node(list_nodes_t *list_obj){
    status_t ret;
    node_t *lastnode;
    if(NULL == list_obj)
    {
        ret = null_pointer;
    }
    else
    {
        if(list_obj->list_head == NULL)
        {
            list_obj->list_head = create_node();
            
        }
        else
        {
            lastnode = list_obj->list_head;
            while(lastnode->link != NULL)
            {
                lastnode = lastnode->link;
            }
            lastnode->link = create_node();
            

        }
        list_obj->nodes_number++;
        ret = all_ok;
    }
return ret;

}


//****************************************

status_t insert_node_at_begining(list_nodes_t *list_obj){

    status_t ret;
    node_t *inserted_node;
    if(NULL == list_obj)
    {
        ret  = null_pointer;
    }
    else
    {
       inserted_node = create_node();
       inserted_node->link = list_obj->list_head;
       list_obj->list_head = inserted_node;
       list_obj->nodes_number++;
       ret = node_inserted;
    }
    return ret;
}

//************insert node at certain postion**********

status_t insert_node_at_cretain_position(list_nodes_t *list_obj){
        status_t ret;
        node_t *prev_node;
        node_t *inserted_node;
        unsigned int position;
        unsigned int counter = 1;
        if(NULL == list_obj)
        {
            ret = null_pointer;
        }
        else
        {
            printf("\nEnter postion of node: ");
            scanf("%d",&position);
            if(position>list_obj->nodes_number+1)
            {
                printf("invalid position !!\n");
            }
            else
            {
                if(1 == position) 
                {
                      inserted_node = create_node();
                      inserted_node->link = list_obj->list_head;
                      list_obj->list_head = inserted_node; 
                }
                else
                {
                    if(position == (list_obj->nodes_number)+1)
                    {
                        prev_node = list_obj->list_head;
                        while(counter<list_obj->nodes_number)
                        {
                            prev_node = prev_node->link;
                            counter++;
                        }
                        prev_node->link = create_node();
                        
                    }
                    else
                    {
                        prev_node = list_obj->list_head;
                        while(counter<position-1)
                        {
                            prev_node = prev_node->link;
                            counter++;
                        }
                        inserted_node = create_node();
                        inserted_node->link = prev_node->link;
                        prev_node->link = inserted_node;


                    }

               
                }
                list_obj->nodes_number++; //increase number at any of three cases. 
                ret = node_inserted;
            }


        }
  return ret;

}

//******************swap two nodes************************
status_t sawp_two_nodes(list_nodes_t *list_obj){
      status_t ret;
      unsigned int counter = 1;
      unsigned int node1_position;
      unsigned int node2_position;
      node_t *node1 = list_obj->list_head;
      node_t *node2 = list_obj->list_head;
      data_t temp;
      if(NULL == list_obj)
      {
          ret = null_pointer;
      }
      else
      {
          if(list_obj->nodes_number == 0)
          {
              ret = empty_list;
              printf("\nempty list !!\n");
          }
          else
          {   printf("\nEnter positions of two nodes: ");
              scanf("%d%d",&node1_position,&node2_position);
              while(counter<node1_position || counter<node2_position)
              {   if(counter<node1_position )
                  {
                      node1 = node1->link;
                  }
                  if( counter<node2_position<node2_position)
                  {
                      node2 = node2->link;
                  }    
                  counter++;
              }
              temp = node1->data;
              node1->data = node2->data;
              node2->data = temp;

              ret = all_ok;
          }
      }
    return ret;
}


//*************delete node at position******************

status_t delete_node_at_psition(list_nodes_t *list_obj){
       status_t ret;
       node_t *prev_node;
       node_t *next_node;
       node_t *deleted_node;
       unsigned int position;
       unsigned int counter = 1;

       if(NULL == list_obj)
       {
           ret = null_pointer;
       }
       else
       {
            printf("\nEnter position of node to delete : ");
            scanf("%d",&position);
            if(position>list_obj->nodes_number)
            {
                printf("invalid position !!\n");
            }
            else
            {
                if(1 == position)
                {
                    deleted_node = list_obj->list_head;
                    list_obj->list_head = deleted_node->link;
                    free(deleted_node);
                }
                else if(position == list_obj->nodes_number)
                {
                    prev_node = list_obj->list_head;
                    while(counter<position-1)
                    {
                        prev_node = prev_node->link;
                        counter++;
                    }
                    deleted_node = prev_node->link;
                    prev_node->link = NULL;
                    free(deleted_node);


                }
                else
                {
                    prev_node = list_obj->list_head;
                    while(counter<position-1)
                    {
                        prev_node = prev_node->link;
                        counter++;
                    }
                    deleted_node = prev_node->link;
                    prev_node->link = deleted_node->link;
                    free(deleted_node);

                }
                ret = node_deleted;
                list_obj->nodes_number--;
            }
       }
       return ret;
}


//**************search on node*****************

node_t *search_on_node(list_nodes_t *list_obj){
        status_t ret;
        unsigned int searched_data;
        node_t *searched_node;
        if(NULL == list_obj)
        {
            ret = null_pointer;
            searched_node = NULL;
        }
        else
        {
            printf("\nEnter data of node : ");
            scanf("%d",&searched_data);
            searched_node = list_obj->list_head;
            if((searched_node->link == NULL) && (searched_data == searched_node->data))
            {
                return searched_node;
            }
            while(searched_node->link != NULL)
            {
                if(searched_data == searched_node->data)
                {
                    break;
                }
                searched_node = searched_node->link;
            }


        }
    return searched_node;
}

//*************modify data in node************
status_t modify_node_data(list_nodes_t *list_obj){
        status_t ret;
        node_t *modified_node;
        data_t new_data;
        if(NULL == list_obj)
        {
            ret = null_pointer;
        }
        else
        { 
            modified_node = search_on_node(list_obj);
            if(NULL != modified_node)
            {
                printf("\nEnter new data: ");
                scanf("%d",&(modified_node->data));
            }
             ret = all_ok;
        }
    return ret;
}

//*************delete node by its value************
status_t delete_node_by_value(list_nodes_t *list_obj){
       status_t ret;
       node_t *deleted_node;
       node_t *prev_node;
       if(NULL == list_obj)
       {
           ret = null_pointer;
       }
       else
       {
           if(list_obj->nodes_number == 0)
           {
              ret = empty_list;
              printf("\nlist is empty!!\n");
           }
           else
           {
               deleted_node = search_on_node(list_obj);

               if(deleted_node == list_obj->list_head)
               {
                   list_obj->list_head = deleted_node->link;
                   
               }
               else if(deleted_node->link == NULL)
               {
                   prev_node = find_previos_of_node(list_obj,deleted_node);
                   prev_node->link = NULL;
               }
               else
               {
                   prev_node = find_previos_of_node(list_obj,deleted_node);
                   prev_node->link = deleted_node->link;
               }
             free(deleted_node);
             list_obj->nodes_number--;  
             ret = node_deleted;       
           }
       }
       return ret;
}

//*************reverse list*********************
status_t reverse_list(list_nodes_t *list_obj){
       status_t ret;
       node_t *next_node = list_obj->list_head->link;
       node_t *temp_link;
       if(NULL == list_obj)
       {
           ret = null_pointer;
       }
       else
       {
           if(list_obj->nodes_number == 0)
           {
               ret = empty_list;
               printf("list is empty !!\n");

           }
           else
           {
              list_obj->list_head->link = NULL;
              while(NULL != next_node)
              {   temp_link = next_node->link;
                  next_node->link = list_obj->list_head;
                  list_obj->list_head = next_node;
                  next_node = temp_link;
              }
              ret = all_ok;
           }
       }
       return ret;
}

//***************sort list*********************
status_t sort_list(list_nodes_t *list_obj){
        status_t ret;
        node_t *first_node = list_obj->list_head;
        node_t *second_node = list_obj->list_head->link;
        unsigned int counter_1;
        unsigned int counter_2;
        data_t temp;
        if(NULL == list_obj)
        {
            ret = null_pointer;
        }
        else
        {
            if(list_obj->nodes_number == 0)
            {
                ret = empty_list;
                printf("list is empty !!\n");
            }
            else
            {
                
              
                 while(first_node->link != NULL)
                {    
                    while(second_node != NULL)
                    {
                        if(first_node->data > second_node->data)
                        {
                            temp = first_node->data;
                            first_node->data = second_node->data;
                            second_node->data = temp;

                        }
                       
                        second_node = second_node->link;
                    }
                     first_node = first_node->link;
                     second_node = first_node->link;
               
                }
               ret = all_ok;
            }
        }
    return ret;
}

//**************display list*********************

status_t display_list(list_nodes_t *list_obj){

node_t *temp;
status_t ret;
unsigned int counter = 1;

    if(NULL == list_obj)
    {
        ret = null_pointer;
    }
    else
    {
        if(list_obj->nodes_number == 0)
        {
                ret = empty_list;
            
        }
        else
        {
                temp = list_obj->list_head;
                printf("list : ");
                while (counter<=list_obj->nodes_number)
                {
                        printf("%d  ",temp->data);
                        counter++;
                        temp = temp->link;
                    
                }
                ret = all_ok;
        }

    }
    return ret;

}


//****************traverse function**********************

node_t *find_previos_of_node(list_nodes_t *list_obj,node_t*node_obj){
       node_t *prev_node;
       node_t *traversing_node = list_obj->list_head;
       while(traversing_node != node_obj)
       {
           prev_node = traversing_node;
           traversing_node = traversing_node->link;
       }
    return prev_node;
}