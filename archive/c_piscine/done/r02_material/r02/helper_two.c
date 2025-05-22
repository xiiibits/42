/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:34:50 by afahs             #+#    #+#             */
/*   Updated: 2025/04/29 10:26:06 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*fill_three(int i, char *str)
{
	char	*res;
	int		n;

	n = 0;
	res = malloc(4);
	res[n++] = str[i++];
	if (str[i])
		res[n++] = str[i++];
	if (str[i])
		res[n++] = str[i++];
	res[n] = '\0';
	return (res);
}

char	**segmentation(char *str)
{
	char	**res;
	int		n;
	int		i;
	int		j;

	j = 0;
	n = get_num_of_segmants_from_char(str);
	i = 0;
	res = malloc((n + 1) * sizeof(char *));
	while (i < ft_strlen(str))
	{
		res[j] = fill_three(i, str);
		i += 3;
		j++;
	}
	res[j] = NULL;
	j = 0;
	while (j < n)
	{
		reverse_string(res[j]);
		j++;
	}
	return (res);
}

int	*stoi(char *s)
{
	int	*n;
	int	i;

	n = malloc(3 * sizeof(int));
	i = 0;
	while (s[i])
	{
		n[i] = (s[i] - '0');
		i++;
	}
	while (i != 3)
	{
		n[i] = 0;
		i++;
	}
	return (n);
}

void	print_single_segment(int *nb, char ***dic)
{
	if (nb[2] > 0)
	{
		ft_putstr(dic[0][nb[2]]);
		ft_putstr(dic[1][9]);
	}
	if (nb[1] > 1)
		ft_putstr(dic[1][nb[1] - 1]);
	if (nb[1] == 1)
	{
		ft_putstr(dic[0][nb[0] + 10]);
		return ;
	}
	if (nb[0] > 0)
		ft_putstr(dic[0][nb[0]]);
}

void	print_the_holy_number(char **nums, char ***dic)
{
	int	*seg;
	int	i;

	i = ft_arrlen(nums) - 1;
	while (i >= 0)
	{
		reverse_string(nums[i]);
		seg = stoi(nums[i]);
		print_single_segment(seg, dic);
		ft_putstr(dic[2][i]);
		i--;
	}
}
