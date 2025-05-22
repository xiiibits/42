/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:34:51 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 21:59:04 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	total_length(char **strs, int size)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		if (strs[i])
		{
			j = 0;
			while (strs[i][j])
			{
				n++;
				j++;
			}
			i++;
		}
	}
	return (n);
}

char	*cal2(int size, char **strs, char *ptr, char *sep)
{
	int	i;
	int	k;
	int	j;
	int	s;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			ptr[k++] = strs[i][j++];
		if (i < size - 1 && sep)
		{
			s = 0;
			while (sep[s])
				ptr[k++] = sep[s++];
		}
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	int		total;
	int		sep_len;

	if (!sep)
		sep = "";
	if (size <= 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	total = total_length(strs, size) + sep_len * (size - 1) + 1;
	ptr = malloc(sizeof(char) * total);
	if (!ptr)
		return (NULL);
	return (cal2(size, strs, ptr, sep));
}
