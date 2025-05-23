/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:33:59 by afahs             #+#    #+#             */
/*   Updated: 2025/05/22 17:08:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;

	i = 0;
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < nmemb * size)
		res[i++] = 0;
	return (res);
}
