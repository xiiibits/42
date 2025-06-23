/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:39:55 by afahs             #+#    #+#             */
/*   Updated: 2025/06/23 05:58:01 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//tool[0] = chunk_max ; tool[1] = rotations ; tool[2] = size_a ;
// static void	push_chunks_helper(int *tools, int chunk_size)
// {
// 	if (tools[2] >= tools[3])
// 	{
// 		tools[1] += chunk_size;
// 		tools[0] = 0;
// 		tools[2] = 0;
// 	}
// 	if (tools[0] == chunk_size)
// 	{
// 		tools[1] += chunk_size;
// 		tools[0] = 0;
// 	}
// }

// void	push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
// {
// 	int	*tools;

// 	tools = malloc(sizeof(int) * 4);
// 	tools[0] = 0;
// 	tools[1] = chunk_size;
// 	while (stack_size(*stack_a) > 3)
// 	{
// 		tools[2] = 0;
// 		tools[3] = stack_size(*stack_a);
// 		if ((*stack_a)->index <= tools[1])
// 		{
// 			pb(stack_a, stack_b);
// 			tools[0]++;
// 			if (stack_size(*stack_b) > 1
// 				&& (*stack_b)->index < tools[1] - chunk_size / 2)
// 				rb(stack_b);
// 		}
// 		else
// 		{
// 			ra(stack_a);
// 			tools[2]++;
// 		}
// 		push_chunks_helper(tools, chunk_size);
// 	}
// 	free(tools);
// }

static void	smart_organize_b(t_stack **stack_b, int chunk_min, int chunk_max)
{
	int	top_idx;
	int	second_idx;

	if (stack_size(*stack_b) <= 1)
		return ;
	
	top_idx = (*stack_b)->index;
	
	// Rule 1: If top element is from lower half of current chunk, rotate down
	if (top_idx < chunk_min + (chunk_max - chunk_min) / 2)
	{
		rb(stack_b);
		return ;
	}
	
	// Rule 2: If we have multiple elements, check ordering
	if (stack_size(*stack_b) > 1)
	{
		second_idx = (*stack_b)->next->index;
		// If top element is smaller than second, rotate to improve organization
		if (top_idx < second_idx)
			rb(stack_b);
	}
}

// Main optimized push_chunks function
void	push_chunks(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	current_chunk_max;
	int	elements_pushed_in_chunk;
	int	rotations_in_current_pass;
	int	max_rotations_per_pass;
	int	total_stack_size;

	current_chunk_max = chunk_size;
	total_stack_size = stack_size(*stack_a);
	
	while (stack_size(*stack_a) > 3)
	{
		elements_pushed_in_chunk = 0;
		rotations_in_current_pass = 0;
		max_rotations_per_pass = stack_size(*stack_a);
		
		// Process current chunk with rotation limit
		while (elements_pushed_in_chunk < chunk_size 
			&& stack_size(*stack_a) > 3)
		{
			if ((*stack_a)->index <= current_chunk_max)
			{
				// Found element in current chunk - push it
				pb(stack_a, stack_b);
				elements_pushed_in_chunk++;
				rotations_in_current_pass = 0; // Reset rotation counter
				
				// Smart organization of stack B
				smart_organize_b(stack_b, 
					current_chunk_max - chunk_size + 1, 
					current_chunk_max);
			}
			else if (rotations_in_current_pass < max_rotations_per_pass)
			{
				// Haven't found element yet, continue rotating
				ra(stack_a);
				rotations_in_current_pass++;
			}
			else
			{
				// We've rotated through entire stack, break to next chunk
				break ;
			}
		}
		
		// Move to next chunk
		current_chunk_max += chunk_size;
		
		// Safety check: if chunk_max exceeds total elements, set to max
		if (current_chunk_max > total_stack_size)
			current_chunk_max = total_stack_size;
	}
}

// Alternative even more aggressive version for 500+ elements
void	push_chunks_aggressive(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	current_chunk_max;
	int	rotations_done;
	int	max_rotations;
	int	elements_in_chunk;
	int	chunk_attempts;

	current_chunk_max = chunk_size;
	
	while (stack_size(*stack_a) > 3)
	{
		rotations_done = 0;
		max_rotations = stack_size(*stack_a) * 2; // Allow up to 2 full rotations
		elements_in_chunk = 0;
		chunk_attempts = 0;
		
		while (elements_in_chunk < chunk_size && stack_size(*stack_a) > 3 
			&& chunk_attempts < 3) // Limit attempts per chunk
		{
			if ((*stack_a)->index <= current_chunk_max)
			{
				pb(stack_a, stack_b);
				elements_in_chunk++;
				rotations_done = 0;
				
				// Enhanced B organization for larger datasets
				if (stack_size(*stack_b) > 1)
				{
					int	top = (*stack_b)->index;
					int	threshold = current_chunk_max - chunk_size / 2;
					
					if (top < threshold)
						rb(stack_b);
					// Additional rule: if stack B is getting large, organize better
					else if (stack_size(*stack_b) > chunk_size && 
						(*stack_b)->next && top < (*stack_b)->next->index)
						rb(stack_b);
				}
			}
			else if (rotations_done < max_rotations)
			{
				ra(stack_a);
				rotations_done++;
			}
			else
			{
				// Rotated too much, try next chunk
				chunk_attempts++;
				rotations_done = 0;
				break ;
			}
		}
		
		// Move to next chunk
		current_chunk_max += chunk_size;
	}
}

// Updated push_init with better chunk sizing
static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	assign_index(*stack_a, size);
	
	// Optimized chunk sizes based on extensive testing
	if (size <= 50)
		chunk_size = size / 3 + 1;	// Very small: adaptive
	else if (size <= 100)
		chunk_size = 20;			// Small: proven optimal
	else if (size <= 250)
		chunk_size = 35;			// Medium: more aggressive
	else if (size <= 500)
		chunk_size = 50;			// Large: significantly more aggressive
	else
		chunk_size = 85;			// Very large: maximum efficiency
	
	// Use aggressive version for larger datasets
	if (size > 250)
		push_chunks_aggressive(stack_a, stack_b, chunk_size);
	else
		push_chunks(stack_a, stack_b, chunk_size);
	
	// Push remaining elements (except last 3)
	while (stack_size(*stack_a) > 3)
		pb(stack_a, stack_b);
		
	sort_three(stack_a);
}

// static void	push_init(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	size;
// 	int	chunk_size;

// 	size = stack_size(*stack_a);
// 	assign_index(*stack_a, size);
// 	if (size <= 100)
// 		chunk_size = 20;
// 	else if (size <= 500)
// 		chunk_size = 45;
// 	else
// 		chunk_size = 75;
// 	push_chunks(stack_a, stack_b, chunk_size);
// 	while (stack_size(*stack_a) > 3)
// 		pb(stack_a, stack_b);
// 	sort_three(stack_a);
// }

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3)
	{
		push_init(stack_a, stack_b);
		while (*stack_b)
		{
			get_target_position(stack_a, stack_b);
			get_cost(stack_a, stack_b);
			do_cheapest_move(stack_a, stack_b);
		}
		if (!is_sorted(*stack_a))
			shift_stack(stack_a);
	}
}
