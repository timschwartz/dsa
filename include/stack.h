#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct stack64_t
{
    uint64_t *stack;
    uint64_t size;
    uint64_t sp;
    
} stack64_t;

stack64_t stack64(uint64_t size);
uint64_t stack64_pop(stack64_t *stack);
void stack64_push(stack64_t *stack, uint64_t value);
bool stack64_is_empty(stack64_t *stack);
uint64_t stack64_peek(stack64_t *stack);
