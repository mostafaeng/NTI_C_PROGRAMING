#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdlib.h>
#include<stdio.h>
typedef int data_t;


typedef struct node
{
    data_t data;
    struct node *link;
}node_t;

typedef struct 
{
     node_t *list_head;
     unsigned int nodes_number;

}list_nodes_t;

typedef enum {
    null_pointer,
    empty_list,
    node_inserted,
    node_deleted,
    all_ok,
    
}status_t;





//*************module function********************

list_nodes_t *create_list(void);
node_t *create_node(void);
status_t append_node(list_nodes_t *list_obj);
status_t insert_node_at_begining(list_nodes_t *list_obj);
status_t insert_node_at_cretain_position(list_nodes_t *list_obj);
status_t delete_node_at_psition(list_nodes_t *list_obj);
status_t delete_node_by_value(list_nodes_t *list_obj);
node_t *search_on_node(list_nodes_t *list_obj);
status_t display_list(list_nodes_t *list_obj);
status_t reverse_list(list_nodes_t *list_obj);
status_t sort_list(list_nodes_t *list_obj);
status_t sawp_two_nodes(list_nodes_t *list_obj);
status_t modify_node_data(list_nodes_t *list_obj);
















#endif