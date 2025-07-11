/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 23:39:55 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 21:57:15 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

static void	push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	half;

	size = stack_size(*stack_a);
	assign_index(*stack_a, size);
	if (size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	half = size / 2;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index <= half)
		{
			pb(stack_a, stack_b, 1);
			if (stack_size(*stack_b) > 1 && (*stack_b)->index < half / 2)
				rb(stack_b, 1);
		}
		else if (stack_size(*stack_a) > half)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2 && !is_sorted(*stack_a))
		sa(stack_a, 1);
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
