/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:29:32 by afahs             #+#    #+#             */
/*   Updated: 2025/04/29 18:46:25 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*n;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = malloc((max - min) * sizeof(int *));
	if (!n)
		return (-1);
	while (i < (max - min))
	{
		n[i] = min + i;
		i++;
	}
	*range = n;
	return (max - min);
}
