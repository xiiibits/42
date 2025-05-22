/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 06:05:03 by afahs             #+#    #+#             */
/*   Updated: 2025/04/17 02:15:33 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb, int b, char *bas)
{
	char		x;
	char		i;
	long int	n;

	n = nb;
	if (n < 0)
	{
		i = '-';
		write(1, &i, 1);
		n = -n;
	}
	if (n / b == 0)
	{
		i = bas[n % b];
		write(1, &i, 1);
	}
	else
	{
		x = bas[n % b];
		ft_putnbr((n / b), b, bas);
		write(1, &x, 1);
	}
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if ((!base[0]) || (!base[1]))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (is_valid(base))
	{
		ft_putnbr(nbr, ft_strlen(base), base);
	}
}
