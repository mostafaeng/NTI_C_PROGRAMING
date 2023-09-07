#include"d_stack.h"
static stack_state check_if_stack_empty(d_stack_t*obj);
 static stack_state check_if_stack_full(d_stack_t*obj);

//********** create stack ****************
d_stack_t*create_d_stack(unsigned int array_size,stack_state*ret_state){

d_stack_t *temp_stack = NULL;
    if(ret_state == NULL){
        *ret_state = stack_null;
    }
    else{
        temp_stack = (d_stack_t *)calloc(1,sizeof(d_stack_t));
        if(temp_stack){
            temp_stack->d_array = (data_t**)calloc(array_size,sizeof(data_t*));
            if(temp_stack->d_array){
                temp_stack->max_size  = array_size;
                temp_stack->s_pointer = -1;
                temp_stack->elem_count = 0;
                *ret_state = ALL_OK;
            }
            else{
                free(temp_stack);
                *ret_state = stack_null;
            }
        }


    }

  return temp_stack;


}

//***************push to stack*******************

stack_state push_d_stack(d_stack_t*obj,data_t *pushed_data){
  
     stack_state ret_state = ALL_OK;
     if((NULL == obj) ||( NULL == pushed_data)){
         ret_state = stack_null;
     }
     else{
        if(stack_not_full == check_if_stack_full(obj)){
            (obj->s_pointer)++;
            obj->d_array[obj->s_pointer] = pushed_data;
            (obj->elem_count)++;
        }
        else{
            ret_state = stack_full;
            printf("error !! stack is full\n\n");
        }
     }
   return ret_state;
}


//***************pop from stack*******************
data_t *pop_d_stack(d_stack_t*obj,stack_state *ret_state){
      *ret_state = ALL_OK;
      data_t *temp;
      if((NULL == obj) || (ret_state == NULL)){
            *ret_state = stack_null;
            temp = NULL;
      }
      else{
            if(stack_not_empty == check_if_stack_empty(obj)){
                  temp = obj->d_array[obj->s_pointer];
                  (obj->s_pointer)--;
                  (obj->elem_count)--;
            }
            else{
                
                *ret_state = stack_empty;
                temp = NULL;
                
                printf("error !! stack is empty\n\n");
            }
      }
  return temp;

}


//***************display stack*******************
void display_stack(d_stack_t*obj,stack_state *ret_state){
       unsigned int counter;
       if(NULL == obj || NULL == ret_state){
            *ret_state = stack_null;
       }
       else{
          for(counter = 0; counter<obj->max_size; counter++){
               if(stack_not_empty == check_if_stack_empty(obj)){
                    if(obj->d_array[counter]){
                        printf("element [%d] : %d\n",counter+1,*(obj->d_array[counter]));

                    }
               }
               else{
                     *ret_state = stack_empty;
                     printf("stack is empty !!\n");
                     break;
               }
           
          } 
       }


}

//*************************find top of stack********************
data_t *find_stack_top(d_stack_t *obj,stack_state *ret_state){
        data_t *temp;
        if((NULL == obj) || (NULL == ret_state)){
            *ret_state = stack_null;
            temp = NULL;
        }
        else{
               if(stack_not_empty == check_if_stack_empty(obj)){
                   temp = obj->d_array[obj->s_pointer];
                  *ret_state = ALL_OK;
               }
               else{
                   *ret_state = stack_empty;
                   printf("stack is empty !!\n");
               }
               
        }
    return temp;
}


//************************find num of elem in stack************************
unsigned int find_num_of_stack_elem(d_stack_t *obj,stack_state *ret_state){

   if((NULL == obj) || (NULL == ret_state)){
        *ret_state = stack_null;
   }
   else{
        if(stack_empty == check_if_stack_empty(obj)){
            *ret_state = stack_empty;
            return 0;
        }
        else{
            return (obj->elem_count);
        }
   }


}

//***************distroy stack********************
d_stack_t *distory_stack(d_stack_t *obj){
    d_stack_t *temp;
    free(obj->d_array);
    free(obj);
    temp = NULL;
}






//************* helper function **********************

 stack_state check_if_stack_full(d_stack_t*obj){
    if((obj->max_size)-1 == obj->s_pointer){
        return stack_full;
    }
    else{
        return stack_not_full;
    }
}

stack_state check_if_stack_empty(d_stack_t*obj){
    if(-1 == obj->s_pointer){
        return stack_empty;
    }
    else{
        return stack_not_empty;
    }

}