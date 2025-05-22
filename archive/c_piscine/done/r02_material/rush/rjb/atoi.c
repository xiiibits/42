/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:48:45 by afahs             #+#    #+#             */
/*   Updated: 2025/04/27 22:55:51 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 65) || ((str[i] > 90)
				&& (str[i] < 97)) || (str[i] > 122))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*correct_string(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(str[i]));
	while (!(ft_str_is_alpha(str[i])))
	{
		i++;
	}
	while (ft_str_is_alpha(str[i]) || (str[i] > 32 && str[i]))
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	return (new_str);
}
