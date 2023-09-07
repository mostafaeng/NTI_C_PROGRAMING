#include"qeueu.h"
static q_state check_if_qeueu_empty(qeueu_t *obj);
static q_state check_if_qeueu_full(qeueu_t *obj);

//*******************create_qeueu*************************
qeueu_t *create_qeueu(unsigned int size, q_state *ret_state){
       qeueu_t*temp;
       if(NULL == ret_state)
       {
            *ret_state = q_null;
       }
       else
       {
            temp = (qeueu_t *)calloc(1,sizeof(qeueu_t));
            if(temp)
            {
                    temp->array = (data_t**)calloc(size,sizeof(data_t*));
                    if(temp->array)
                    {
                        temp->front = -1;
                        temp->rear = -1;
                        temp->array_size = size;
                        temp->elem_count = 0;

                        *ret_state = ALL_OK;
                    }
                    else{
                        free(temp);
                        temp = NULL;
                        *ret_state = q_null;
                    }
            }
       }
   return temp;
}


//*******************Enqeueu_data*****************************
q_state Enqeueu_data(qeueu_t *obj,data_t *enq_data){
        q_state ret_state;
        if((NULL == obj) || (NULL == enq_data))
        {
              ret_state = q_null;
        }
        else
        {
            if(q_not_full == check_if_qeueu_full(obj))
            {
                (obj->rear)++;
                if(obj->array_size == obj->rear)
                {
                     obj->rear = 0;
                }

                if(obj->elem_count == 0)
                {
                   obj->front = 0;
                   obj->elem_count = 1;
                }
                else{
                    (obj->elem_count)++;
                }

                obj->array[obj->rear] = enq_data;
                ret_state =ALL_OK;

            }
            else
            {
                 ret_state = q_full;
                 printf("qeueu is full !!\n\n");
            }
            
                
        }
        return ret_state;

}


//*********************Deqeueu_data*********************
data_t *Deqeueu_data(qeueu_t *obj,q_state *ret_state){
       data_t*temp;
       if((NULL == obj) || (NULL == ret_state))
       {
              *ret_state = q_null;
              temp = NULL;
       }
       else
       {
              if(q_not_empty == check_if_qeueu_empty(obj))
              {
                   temp = obj->array[obj->front];
                   (obj->front)++;

                   if(obj->array_size == obj->front)
                   {
                        obj->front = 0;
                   }

                   if(1 == obj->elem_count)
                   {
                        obj->front = -1;
                        obj->rear = -1;
                        obj->elem_count = 0;
                   }
                   else
                   {
                        (obj->elem_count)--;    
                   }

              }
              else
              {
                printf("qeueu is empty !!\n");
                temp = NULL;
              }
       }
  return temp;
}


//****************free qeueu**********************************
qeueu_t *free_qeueu(qeueu_t *obj){
     free(obj->array);
     free(obj);
     return NULL;
}




//*************************helper function**********************

q_state check_if_qeueu_empty(qeueu_t *obj){
      if(0 == obj->elem_count){
        return q_empty;
      }
      else{
        return q_not_empty;
      }

}

q_state check_if_qeueu_full(qeueu_t *obj){
      if(obj->array_size == obj->elem_count){
        return q_full;
      }
      else{
        return q_not_full;
      }

}

