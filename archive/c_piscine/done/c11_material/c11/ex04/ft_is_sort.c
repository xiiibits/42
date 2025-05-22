/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:31:03 by afahs             #+#    #+#             */
/*   Updated: 2025/05/01 21:38:58 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asen;
	int	desn;

	i = 0;
	asen = 0;
	desn = 0;
	while (i < (length - 1))
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			asen++;
		if (f(tab[i], tab[i + 1]) <= 0)
			desn++;
		i++;
	}
	if (asen == i || desn == i)
		return (1);
	return (0);
}
