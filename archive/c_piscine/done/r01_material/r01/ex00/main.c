/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:48:49 by afahs             #+#    #+#             */
/*   Updated: 2025/04/20 16:57:14 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// Prototypes of needed function
int		is_valid(char *input);
void	fill_zeros(int solution[4][4]);
void	print_solution(int solution[4][4]);
int		*stoi(char *string_input, int int_input[16]);
int		the_holy_grail(int solution[4][4], int input[14], int row, int coloumn);

int	main(int argc, char **argv)
{
	int		solution[4][4];
	int		input[16];

	if (argc != 2 || !is_valid(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fill_zeros(solution);
	stoi(argv[1], input);
	if (the_holy_grail(solution, input, 0, 0))
		print_solution(solution);
	return (0);
}
