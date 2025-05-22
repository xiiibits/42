/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 23:58:19 by afahs             #+#    #+#             */
/*   Updated: 2025/04/14 00:07:40 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 91) && (str[i] > 64))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	str = ft_strlowcase(str);
	i = 0;
	while (str[i])
	{
		if ((str[i - 1] > 64) && (str[i - 1] < 91))
		{
			i++;
		}
		if ((str[i] < 123) && (str[i] > 96))
		{
			if ((str[i - 1] > 122) || (str[i - 1] < 97))
				str[i] = str[i] - 32;
			if (!(str[i - 1] < 48) && (str[i - 1] < 58))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
