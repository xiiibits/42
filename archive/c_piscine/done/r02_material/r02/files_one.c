/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chamas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:51:42 by mchamas           #+#    #+#             */
/*   Updated: 2025/04/27 22:52:45 by mchamas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<fcntl.h>

char	*word(char *str, char *charset)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**helper(char **splitted, int j)
{
	splitted[j] = malloc(sizeof(char));
	if (!splitted[j])
		return (NULL);
	splitted[j] = 0;
	return (splitted);
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int		i;
	int		j;

	splitted = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			splitted[j] = word(&str[i], charset);
			j++;
		}
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (helper(splitted, j));
}
