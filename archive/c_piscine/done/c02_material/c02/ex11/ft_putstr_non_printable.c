/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:19:01 by afahs             #+#    #+#             */
/*   Updated: 2025/04/14 03:44:17 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	m;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] > 0 && str[i] < 32)
		{
			write(1, "\\", 1);
			m = (str[i] / 16) + '0';
			write(1, &m, 1);
			m = "0123456789abcdef"[str[i] % 16];
			write(1, &m, 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
