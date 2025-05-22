/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:14:47 by afahs             #+#    #+#             */
/*   Updated: 2025/04/14 12:03:08 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (src[n] && (n < nb))
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
