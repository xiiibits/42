/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:38:10 by afahs             #+#    #+#             */
/*   Updated: 2025/04/19 03:57:51 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((!s1[i]) && (!s2[i]))
			return (0);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_sort_args(char const **args, int size)
{
	int			i;
	int			j;
	const char	*temp;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(args[i], args[j]) < 0)
			{
				temp = args[i];
				args[i] = args[j];
				args[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	i;
	int	j;

	ft_sort_args(argv, argc);
	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
