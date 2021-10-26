#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct sl_node_t
{
    uint64_t element;
    struct sl_node_t *next;
} sl_node_t;

typedef struct sl_list_t
{
    struct sl_node_t *head;
} sl_list_t;

/** Returns an empty sl_list_t */
sl_list_t sl_list();

/** Returns an empty sl_node_t */
sl_node_t *sl_node_empty();

/** Returns list with element added */
sl_list_t sl_list_add(sl_list_t, uint64_t);

/** Add element after given node, returns pointer to new sl_node_t */
sl_node_t *sl_node_insert_after(sl_node_t *, uint64_t);
sl_node_t *sl_node_remove_after(sl_node_t *);

sl_list_t sl_list_insert_beginning(sl_list_t, uint64_t);
sl_list_t sl_list_remove_beginning(sl_list_t);
