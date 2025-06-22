static void push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
    int pushed;
    int chunk_max;
    int rotations;
    int size_a;

    pushed = 0;
    chunk_max = chunk_size;
    while (stack_size(*stack_a) > 3)
    {
        rotations = 0;
        size_a = stack_size(*stack_a);
        if ((*stack_a)->index <= chunk_max)
        {
            pb(stack_a, stack_b);
            pushed++;
            if (stack_size(*stack_b) > 1 && (*stack_b)->index < chunk_max - chunk_size / 2)
                rb(stack_b);
        }
        else
        {
            ra(stack_a);
            rotations++;
        }
        
        // If we've rotated through the entire stack without finding a number to push
        if (rotations >= size_a)
        {
            chunk_max += chunk_size;
            pushed = 0;
            rotations = 0;
        }
        
        if (pushed == chunk_size)
        {
            chunk_max += chunk_size;
            pushed = 0;
        }
    }
}
