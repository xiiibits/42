/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:51:13 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 21:54:35 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*s) || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, int i)
{
	rotate_stack(a);
	if (i)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	rotate_stack(b);
	if (i)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int i)
{
	rotate_stack(a);
	rotate_stack(b);
	if (i)
		write(1, "rr\n", 3);
}
