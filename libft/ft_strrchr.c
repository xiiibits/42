/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:07:26 by afahs             #+#    #+#             */
/*   Updated: 2025/05/22 15:00:28 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	t;

	t = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == t)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
