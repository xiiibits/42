/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 06:03:31 by afahs             #+#    #+#             */
/*   Updated: 2025/05/01 07:51:37 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*range;

	i = 0;
	while (src[i])
		i++;
	range = malloc((i + 1) * sizeof(char));
	if (!range)
		return (NULL);
	i = 0;
	while (src[i])
	{
		range[i] = src[i];
		i++;
	}
	range[i] = '\0';
	return (range);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*new_arr;
	int			i;

	i = 0;
	new_arr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!new_arr)
		return (NULL);
	while (i < ac)
	{
		new_arr[i].str = av[i];
		new_arr[i].size = ft_strlen(new_arr[i].str);
		new_arr[i].copy = ft_strdup(new_arr[i].str);
		i++;
	}
	new_arr[i].str = 0;
	new_arr[i].size = 0;
	new_arr[i].copy = 0;
	return (new_arr);
}
