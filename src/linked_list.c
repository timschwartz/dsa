#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

sl_node_t *sl_node_empty()
{
    sl_node_t *n = (sl_node_t *)malloc(sizeof(sl_node_t));
    n->next = NULL;
    return n;
}

sl_list_t sl_list()
{
    sl_list_t l;
    l.head = NULL;
    return l;
}

sl_list_t sl_list_add(sl_list_t l, uint64_t element)
{
    sl_node_t *n = sl_node_empty();

    if(l.head != NULL)
    {
        sl_node_t *last = l.head;
        while(last->next != NULL) last = last->next;
        last->next = n;
    }
    else
    {
        l.head = n;
    }

    n->element = element;
    return l;
}

sl_node_t *sl_node_insert_after(sl_node_t *n, uint64_t element)
{
    n->next = sl_node_empty();
    n = n->next;
    n->element = element;
    return n;
}

sl_node_t *sl_node_remove_after(sl_node_t *n)
{
    sl_node_t *next = n->next->next;
    free(n->next);
    n->next = next;
    return next;
}

sl_list_t sl_list_insert_beginning(sl_list_t l, uint64_t element)
{
    sl_node_t *n = sl_node_empty();
    n->element = element;
    n->next = l.head;
    l.head = n;
    return l;
}

sl_list_t sl_list_remove_beginning(sl_list_t l)
{
    sl_node_t *next = l.head->next;
    free(l.head);
    l.head = next;
    return l;
}
