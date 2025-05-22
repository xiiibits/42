/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:48:45 by afahs             #+#    #+#             */
/*   Updated: 2025/04/27 23:17:35 by mchamas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65) || ((str[i] > 90)
				&& (str[i] < 97)) || (str[i] > 122))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	correct_string(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(str[i]));
	while (!(ft_str_is_alpha(str[i])))
	{
		i++;
	}
	while (ft_str_is_alpha(str[i]) || (str[i] > 32 && str[i]))
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	j = 0;
	while (new_str[j])
	{
		str[j] = new_str[j];
	}
	str[j] = '\0';
}

void	fill_the_first(char **arr, char *file)
{
	arr = ft_split(put_dic_in_string(file), "\n");
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
