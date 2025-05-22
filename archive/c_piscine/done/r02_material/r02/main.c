/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 22:43:23 by kzebian           #+#    #+#             */
/*   Updated: 2025/04/27 23:38:44 by mchamas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	char	**r;
	char	**ones;
	char	**tens;
	char	**extra;
	char	***dictionarty;

	if (argc == 2)
	{
		ones = malloc(20 * sizeof(char *));
		tens = malloc(10 * sizeof(char *));
		extra = malloc(13 * sizeof(char *));
		fill_ones(ones);
		fill_tens(tens);
		fill_extra(extra);
		dictionarty = malloc(3 * sizeof(char **));
		dictionarty[0] = ones;
		dictionarty[1] = tens;
		dictionarty[2] = extra;
		reverse_string(argv[1]);
		r = segmentation(argv[1]);
		print_the_holy_number(r, dictionarty);
	}
	return (0);
}
