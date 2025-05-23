/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:28:59 by afahs             #+#    #+#             */
/*   Updated: 2025/05/23 03:07:36 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		while (s[i] == c)
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		j;
	char	**res;

	count = count_words(s, c);
	res = (char **)malloc(count);
	if (!res)
		return (NULL);
	i = 0;
	while (i <= count)
	{
		j = 0;
		while (s[j] != c)
			j++;
		res[i] = malloc(j + 1);
		if (!res[i])
			return (NULL);
		j = 0;
		while (s[j])
			
	}
}
void	fill_word()