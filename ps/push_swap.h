/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:40:28 by afahs             #+#    #+#             */
/*   Updated: 2025/06/19 12:31:04 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
}	t_stack;

long	ft_atol(const char *str);
long	*built_array(char **s, int size);
int		is_valid(char *s);
int		check_dups(long *n, int size);
t_stack	*new_node(int value);
void	add_front(t_stack **stack, t_stack *node);
t_stack	*parse_args(int c, char **v);
void	free_stack(t_stack *s);

#endif