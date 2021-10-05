#include <stack.h>
#include <stdlib.h>

stack64_t stack64(uint64_t size)
{
    stack64_t s;
    s.sp = 0;
    s.size = size;
    s.stack = (uint64_t *)malloc(sizeof(uint64_t) * size);
    return s;
}

bool stack64_is_empty(stack64_t *stack)
{
    if(stack->sp == 0) return true;
    return false;
}

void stack64_push(stack64_t *stack, uint64_t value)
{
    stack->stack[stack->sp] = value;
    stack->sp++;
}

uint64_t stack64_pop(stack64_t *stack)
{
    stack->sp--;
    return stack->stack[stack->sp];
}

uint64_t stack64_peek(stack64_t *stack)
{
    return stack->stack[(stack->sp - 1)];
}
