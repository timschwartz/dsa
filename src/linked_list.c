#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

linked_list *EmptyList()
{
    linked_list *l = (linked_list *)malloc(sizeof(linked_list));
    l->element = 0;
    l->next = NULL;    
    l->head = l;
    return l;
}

linked_list *MakeList(uint64_t element, linked_list *l)
{
    linked_list *n = EmptyList();
    n->element = element;
    l->head = n;
    n->next = l;
    return n;
}
