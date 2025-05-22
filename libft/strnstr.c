/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:42 by afahs             #+#    #+#             */
/*   Updated: 2025/05/21 01:48:39 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	j;

	i = 0;
	if (!little[i])
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j])
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (!little[j])
			return (&big[i]);
		i++;
	}
	return (NULL);
}
