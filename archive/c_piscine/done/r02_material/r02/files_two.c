/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:52:07 by mchamas           #+#    #+#             */
/*   Updated: 2025/04/27 23:36:54 by mchamas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<fcntl.h>

char	*put_dic_in_string(char *dicname)
{
	int		fd;
	char	*str;
	char	a;
	char	b;
	int		i;

	i = 0;
	fd = open(dicname, O_RDONLY);
	while (read(fd, &a, 1))
	{
		while (a == ' ')
		{
			read(fd, &b, 1);
			if (b != ' ')
			{
				i++;
				break ;
			}
			a = b;
		}
		i++;
	}
	return (str);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && !is_sep(str[i], charset))
				i++;
		}
	}
	return (count);
}
