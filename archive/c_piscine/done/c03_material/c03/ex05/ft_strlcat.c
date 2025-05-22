/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:06:19 by afahs             #+#    #+#             */
/*   Updated: 2025/05/01 06:37:43 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (dest[i] && i < size)
		i++;
	while (src[n] && ((i + n) < (size - 1)))
	{
		dest[i + n] = src[n];
		n++;
	}
	if (i < size)
		dest[i + n] = '\0';
	while (src[n])
		n++;
	return (i + n);
}
