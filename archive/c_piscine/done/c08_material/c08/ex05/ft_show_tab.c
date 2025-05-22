/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 06:21:08 by afahs             #+#    #+#             */
/*   Updated: 2025/05/01 03:10:40 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	char	c;

	while (*str != '\0')
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	char	x;
	char	i;
	long	n;

	n = nb;
	if (n < 0)
	{
		i = '-';
		write(1, &i, 1);
		n = -n;
	}
	if (n / 10 <= 0)
	{
		i = n + '0';
		write(1, &i, 1);
	}
	else
	{
		x = (n % 10) + '0';
		ft_putnbr(n / 10);
		write(1, &x, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
