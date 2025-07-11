/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:39:22 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:46:37 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*moves_text;
	char	*temp;

	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	temp = ft_strjoin("Moves: ", moves_str);
	free(moves_str);
	if (!temp)
		return ;
	moves_text = temp;
	mlx_string_put(game->mlx, game->window, 10, 20, 0xCCFF00, moves_text);
	free(moves_text);
}

static int	count(int n)
{
	int		c;

	c = 0;
	if (n <= 0)
		c++;
	while (n != 0)
	{
		c++;
		n = n / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		c;
	long	nb;

	nb = n;
	c = count(nb);
	s = malloc(c + 1);
	if (!s)
		return (NULL);
	s[c] = 0;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		s[0] = '0';
	i = c - 1;
	while (nb > 0)
	{
		s[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}
