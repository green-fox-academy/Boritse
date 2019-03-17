#include "linked_list.h"
#include <stdio.h>

int main()
{
    linked_list_node_t *linked_list = linked_list_create();

    linked_list_push_back(linked_list, 10);
    linked_list_push_back(linked_list, 30);
    linked_list_print(linked_list);

    linked_list_push_ahead(&linked_list, 45);
    linked_list_insert_after(linked_list->next->next, 89);
    linked_list_print(linked_list);
    printf("%d", linked_list_size(linked_list));

    linked_list_delete(&linked_list);
    linked_list_print(linked_list);

    linked_list_delete_value(&linked_list, 89);
    linked_list_print(linked_list);

    linked_list_push_ahead(&linked_list, 89);
    linked_list_push_back(linked_list, 89);
    linked_list_print(linked_list);

    linked_list_node_t *sorted_list = linked_list;

    linked_list_sort(&sorted_list);
    linked_list_print(sorted_list);

    linked_list_node_t *search_engine = linked_list_search(sorted_list, 30);
    printf("the search engine is pointing to value: %d, at the address: %p\n", search_engine->value, search_engine);

    search_engine = linked_list_search(sorted_list, 10);
    printf("the search engine is pointing to value: %d, at the address: %p\n", search_engine->value, search_engine);

    linked_list_dealloc(linked_list);

    return 0;
}