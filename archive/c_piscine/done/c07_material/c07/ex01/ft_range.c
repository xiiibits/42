/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:55:49 by afahs             #+#    #+#             */
/*   Updated: 2025/04/28 19:03:49 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*n;
	int	*range;

	i = 0;
	n = NULL;
	range = malloc((max - min) * sizeof(int));
	if (!range)
		return (n);
	if (min >= max)
		return (n);
	while (i < (max - min))
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
