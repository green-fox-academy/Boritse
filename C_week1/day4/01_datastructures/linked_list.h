//
// Created by Borbáls on 2019. 02. 28..
//

#ifndef INC_01_DATASTRUCTURES_LINKED_LIST_H
#define INC_01_DATASTRUCTURES_LINKED_LIST_H

typedef struct linked_list_node
{
  int value;
  struct linked_list_node *next;
} linked_list_node_t;


linked_list_node_t *linked_list_create();
void linked_list_dealloc(linked_list_node_t *linked_list);

void linked_list_push_back(linked_list_node_t *linked_list, int value);

void linked_list_push_ahead(linked_list_node_t **linked_list, int value);

void linked_list_insert_after(linked_list_node_t *existing_node, int value);

void linked_list_print(linked_list_node_t *linked_list);

int linked_list_size(linked_list_node_t *linked_list);

void linked_list_delete(linked_list_node_t **linked_list);

int linked_list_delete_value(linked_list_node_t **linked_list, int value);

linked_list_node_t *linked_list_search(linked_list_node_t *linked_list, int value);

#endif //INC_01_DATASTRUCTURES_LINKED_LIST_H
