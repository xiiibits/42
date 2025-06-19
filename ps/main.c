#include "push_swap.h"

// Helper function to print the stack
void print_stack(t_stack *stack, char *name)
{
    printf("Stack %s: ", name);
    if (!stack)
    {
        printf("(empty)\n");
        return;
    }
    
    while (stack)
    {
        printf("[%d]", stack->value);
        if (stack->next)
            printf(" -> ");
        stack = stack->next;
    }
    printf(" -> NULL\n");
}
