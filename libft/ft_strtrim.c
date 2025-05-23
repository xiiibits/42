/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 23:57:44 by afahs             #+#    #+#             */
/*   Updated: 2025/05/23 00:27:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	char			*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (s1);
	start = 0;
	while (inset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (inset(s1[end], set))
		end--;
	res = (char *)malloc(end - start + 1);
	if (!res)
		return (NULL);
	res = ft_substr(s1, start, (end - start));
	return (res);
}
