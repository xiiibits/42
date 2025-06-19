/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:07:51 by afahs             #+#    #+#             */
/*   Updated: 2025/06/19 12:26:01 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	add_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

t_stack	*build_stack(long *n, int c)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = NULL;
	i = c - 1;
	while (i > 0)
	{
		node = new_node(n[c]);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		add_front(&stack, node);
		i--;
	}
	return (stack);
}

t_stack	*parse_args(int c, char **v)
{
	int		i;
	t_stack	*s;
	long	*n;

	i = 1;
	while (i < c)
	{
		if (!is_valid(v[i]))
			return (NULL);
		i++;
	}
	n = built_array(v, c);
	if (!check_dups(n, c - 1))
	{
		free(n);
		return (NULL);
	}
	s = build_stack(n, c - 1);
	return (s);
}

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}
