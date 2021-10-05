#include <stdio.h>
#include <linked_list.h>
#include <stack.h>

int main(int argc, char *argv[])
{
    stack64_t s = stack64(10);
    stack64_push(&s, 5);
    
    printf("Value: %d\n", stack64_peek(&s));
    return 0;
}
