//
// Created by Borbáls on 2019. 02. 28..
//

#include <malloc.h>
#include <stdio.h>
#include "linked_list.h"

linked_list_node_t *linked_list_create()
{
    linked_list_node_t *linked_list = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));

    linked_list->value = 0;
    linked_list->next = NULL;

    return linked_list;
}

void linked_list_dealloc(linked_list_node_t *linked_list)
{
    linked_list_node_t *node_to_free = linked_list;

    while(node_to_free != NULL) {
        linked_list_node_t *next_node = node_to_free->next;
        free(node_to_free);
        node_to_free = next_node;
    }
}

void linked_list_push_back(linked_list_node_t *linked_list, int value)
{
    // Allocate memory for a new node and initialize it
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->value = value;
    new_node->next = NULL;

    // Iterate through the list to find the last element
    linked_list_node_t *it = linked_list;
    while(it->next != NULL) {
        it = it->next;
    }

    // Set the pointer of the last element to the new node
    it->next = new_node;

    // Alternative loop:
    //for (linked_list_node_t *it = linked_list; it->next != NULL; it = it->next)
}
void linked_list_push_ahead(linked_list_node_t **linked_list, int value)
{
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->value = value;
    new_node->next = *linked_list;

    *linked_list=new_node;
}
void linked_list_print(linked_list_node_t *linked_list)
{
    // Iterate through the list
    linked_list_node_t *it = linked_list;
    while(it != NULL) {
        printf("%p: %d\n", it, it->value);
        it = it->next;
    }
    printf("----------------------------------\n");
}
void linked_list_insert_after(linked_list_node_t *existing_node, int value)
{
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->value = value;
    new_node->next = existing_node->next;
    existing_node->next=new_node;
}
int linked_list_size(linked_list_node_t *linked_list)
{
    int size=0;
    linked_list_node_t *it = linked_list;
    while(it != NULL) {
        size++;
        it = it->next;
    }
    if(size==0){
        printf("your linked list is bloody empty, man");
    }
    return size;
}
void linked_list_delete(linked_list_node_t **linked_list)
{
    linked_list_node_t *temp=*linked_list;
    *linked_list=(*linked_list)->next;
    free(temp);
}
int linked_list_delete_value(linked_list_node_t **linked_list, int value)
{
    int amount_deleted = 0;
    linked_list_node_t *it_before = *linked_list;
    linked_list_node_t *it = *linked_list;
    while (it != NULL) {
        if (it->value == value) {
            linked_list_delete(&it);
            it_before->next = it;
            amount_deleted++;
        } else {
            it_before = it;
            it = it->next;
        }
    }
    return amount_deleted;
}
linked_list_node_t *linked_list_search(linked_list_node_t *linked_list, int value)
{
    linked_list_node_t *it=linked_list;
    while(it != NULL){
        if(it->value==value){
            return it;
        }
        it=it->next;
    }
    return NULL;
}
