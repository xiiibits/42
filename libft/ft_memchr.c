/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:05:35 by afahs             #+#    #+#             */
/*   Updated: 2025/05/22 15:10:12 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	t;
	const char		*temp;

	t = (unsigned char)c;
	temp = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == t)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
