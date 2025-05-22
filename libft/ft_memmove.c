/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:29:40 by afahs             #+#    #+#             */
/*   Updated: 2025/05/21 07:43:59 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp_dst;
	char	*temp_src;
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	temp_dst = (char *) dst;
	temp_src = (char *) src;
	if (temp_dst > temp_src)
		while (len-- > 0)
			temp_dst[len] = temp_src[len];
	else
		while (i++ < len)
			temp_dst[i] = temp_src[i];
	return (dst);
}
