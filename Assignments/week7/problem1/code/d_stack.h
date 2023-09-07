
#include<stdio.h>
#include<stdlib.h>

typedef char data_t;

typedef struct d_stack
{
data_t **d_array;
unsigned int max_size;
int s_pointer;
unsigned int elem_count;  
}d_stack_t;

typedef enum{

stack_null,
stack_full,
stack_not_full,
stack_empty,
stack_not_empty,
ALL_OK

}stack_state;


d_stack_t *create_d_stack(unsigned int array_size,stack_state*ret_state);
stack_state push_d_stack(d_stack_t*obj,data_t *pushed_data);
data_t *pop_d_stack(d_stack_t*obj,stack_state *ret_state);
void display_stack(d_stack_t*obj,stack_state *ret_state);
d_stack_t *distory_stack(d_stack_t *obj);
data_t *find_stack_top(d_stack_t *obj,stack_state *ret_state);
unsigned int find_num_of_stack_elem(d_stack_t *obj,stack_state *ret_state);


