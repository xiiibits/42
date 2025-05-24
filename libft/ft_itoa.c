/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:18:37 by afahs             #+#    #+#             */
/*   Updated: 2025/05/24 06:41:41 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
