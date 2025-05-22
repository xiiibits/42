/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:44:02 by afahs             #+#    #+#             */
/*   Updated: 2025/04/11 15:40:23 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	x;
	int	temp;

	i = 0;
	while (i < size)
	{
		x = i + 1;
		while (x < size)
		{
			if (tab[i] > tab[x])
			{
				temp = tab[i];
				tab[i] = tab[x];
				tab[x] = temp;
			}
			x++;
		}
		i++;
	}
}
