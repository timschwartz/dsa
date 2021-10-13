#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct linked_list_t
{
    uint64_t element;
    struct linked_list_t *next;
    struct linked_list_t *head;
} linked_list_t;

linked_list_t *linked_list();
linked_list_t *linked_list_add(uint64_t, linked_list_t *);
