/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:42:22 by afahs             #+#    #+#             */
/*   Updated: 2025/06/16 16:06:25 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	solve_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
