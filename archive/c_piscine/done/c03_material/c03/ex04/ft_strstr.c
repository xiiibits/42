/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:39:40 by afahs             #+#    #+#             */
/*   Updated: 2025/05/01 06:34:33 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		j = 0;
		while (to_find[j])
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (!to_find[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
