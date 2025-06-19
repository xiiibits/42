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

int main(int argc, char **argv)
{
    t_stack *stack_a;
    
    printf("=== PUSH SWAP PARSING TEST ===\n");
    printf("Command: ");
    for (int i = 0; i < argc; i++)
        printf("%s ", argv[i]);
    printf("\n\n");
    
    // Test parsing
    stack_a = parse_args(argc, argv);
    
    if (!stack_a)
    {
        printf("❌ PARSING FAILED!\n");
        printf("Error: Invalid input detected\n");
        return (1);
    }
    
    printf("✅ PARSING SUCCESSFUL!\n");
    print_stack(stack_a, "A");
    
    // Test basic info about the stack
    int count = 0;
    t_stack *temp = stack_a;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    printf("Stack size: %d elements\n", count);
    
    // Show the first few values
    printf("Top element: %d\n", stack_a->value);
    if (stack_a->next)
        printf("Second element: %d\n", stack_a->next->value);
    
    // Cleanup
    free_stack(stack_a);
    printf("\n✅ Memory cleaned up successfully!\n");
    
    return (0);
}

// Alternative main for automatic testing
/*
int main(void)
{
    // Test cases
    char *test1[] = {"./push_swap", "1", "2", "3"};
    char *test2[] = {"./push_swap", "42", "-17", "100"};
    char *test3[] = {"./push_swap", "1", "2", "1"};  // Duplicate
    char *test4[] = {"./push_swap", "abc"};          // Invalid
    char *test5[] = {"./push_swap", "2147483648"};   // Overflow
    
    printf("=== AUTOMATIC TESTS ===\n\n");
    
    printf("Test 1 - Valid: 1 2 3\n");
    // Simulate argc=4, argv=test1
    t_stack *result1 = parse_args(4, test1);
    if (result1) {
        print_stack(result1, "A");
        free_stack(result1);
    } else {
        printf("❌ Failed (should succeed)\n");
    }
    printf("\n");
    
    printf("Test 2 - Valid: 42 -17 100\n");
    t_stack *result2 = parse_args(4, test2);
    if (result2) {
        print_stack(result2, "A");
        free_stack(result2);
    } else {
        printf("❌ Failed (should succeed)\n");
    }
    printf("\n");
    
    printf("Test 3 - Duplicate: 1 2 1\n");
    t_stack *result3 = parse_args(4, test3);
    if (result3) {
        printf("❌ Succeeded (should fail)\n");
        free_stack(result3);
    } else {
        printf("✅ Correctly rejected duplicates\n");
    }
    printf("\n");
    
    printf("Test 4 - Invalid: abc\n");
    t_stack *result4 = parse_args(2, test4);
    if (result4) {
        printf("❌ Succeeded (should fail)\n");
        free_stack(result4);
    } else {
        printf("✅ Correctly rejected invalid input\n");
    }
    printf("\n");
    
    return (0);
}
*/