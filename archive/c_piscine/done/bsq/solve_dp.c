/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_dp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:28:26 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:28:32 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

static int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= c)
		return (b);
	return (c);
}

int	**alloc_dp(t_mapinfo info)
{
	int	**dp;
	int	i;
	int	j;

	dp = malloc(sizeof(int *) * info.rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < info.rows)
	{
		dp[i] = malloc(sizeof(int) * info.cols);
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (NULL);
		}
		j = 0;
		while (j < info.cols)
			dp[i][j++] = 0;
		i++;
	}
	return (dp);
}

static int	get_dp_val(int **dp, int i, int j)
{
	if (i == 0 || j == 0)
		return (1);
	return (min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1);
}

void	compute_dp(char **map, int **dp, t_mapinfo info, t_sqres *res)
{
	int	i;
	int	j;

	res->size = 0;
	i = 0;
	while (i < info.rows)
	{
		j = 0;
		while (j < info.cols)
		{
			if (map[i][j] == info.obstacle)
				dp[i][j] = 0;
			else
				dp[i][j] = get_dp_val(dp, i, j);
			if (dp[i][j] > res->size)
			{
				res->size = dp[i][j];
				res->row = i;
				res->col = j;
			}
			j++;
		}
		i++;
	}
}
