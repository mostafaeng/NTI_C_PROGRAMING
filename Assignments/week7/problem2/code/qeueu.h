
#ifndef   QEUEU_H
#define   QEUEU_H

#include <stdio.h>
#include<stdlib.h>

typedef char data_t;

typedef struct qeueu
{
data_t **array;
int front;
int rear;
unsigned int array_size;
unsigned int elem_count;
    
}qeueu_t;

typedef enum{
 q_null,
 q_full,
 q_empty,
 q_not_full,
 q_not_empty,
 ALL_OK,
}q_state;


qeueu_t *create_qeueu(unsigned int size, q_state *ret_state);
q_state Enqeueu_data(qeueu_t *obj,data_t *enq_data);
data_t *Deqeueu_data(qeueu_t *obj,q_state *ret_state);
qeueu_t *free_qeueu(qeueu_t *obj);













#endif