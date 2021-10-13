#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

linked_list_t *linked_list()
{
    linked_list_t *l = (linked_list_t *)malloc(sizeof(linked_list_t));
    l->element = 0;
    l->next = NULL;    
    l->head = l;
    return l;
}

linked_list_t *linked_list_add(uint64_t element, linked_list_t *l)
{
    linked_list_t *n = linked_list();
    n->element = element;
    l->head = n;
    n->next = l;
    return n;
}
