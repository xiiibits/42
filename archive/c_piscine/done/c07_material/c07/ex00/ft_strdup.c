/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:47:55 by afahs             #+#    #+#             */
/*   Updated: 2025/04/28 23:39:35 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*range;

	i = 0;
	while (src[i])
		i++;
	range = malloc((i) * sizeof(char));
	if (!range)
		return (NULL);
	i = 0;
	while (src[i])
	{
		range[i] = src[i];
		i++;
	}
	range[i] = '\0';
	return (range);
}
