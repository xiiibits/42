/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 04:26:47 by afahs             #+#    #+#             */
/*   Updated: 2025/04/22 08:42:51 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		p = p * nb;
		i++;
	}
	return (p);
}
