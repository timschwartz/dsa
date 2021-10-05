#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct linked_list
{
    uint64_t element;
    struct linked_list *next;
    struct linked_list *head;
} linked_list;

linked_list *EmptyList();
linked_list *MakeList(uint64_t, linked_list *);
