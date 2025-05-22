/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:36:05 by afahs             #+#    #+#             */
/*   Updated: 2025/04/20 16:59:29 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

// Prototypes of needed function
int		what_see(int i, int ii, int iii, int iv);
int		check_solutions(int sol[4][4], int input[16]);
int		can_put(int sol[4][4], int row, int coloumn, int n);

// The Holy Grail
int	the_holy_grail(int solution[4][4], int input[4], int row, int coloumn)
{
	int	i;

	if (row == 4)
		return (check_solutions(solution, input));
	if (coloumn == 4)
		return (the_holy_grail(solution, input, row + 1, 0));
	i = 0;
	while (i < 4)
	{
		if (can_put(solution, row, coloumn, i + 1))
		{
			solution[row][coloumn] = i + 1;
			if (the_holy_grail(solution, input, row, coloumn + 1))
				return (1);
			solution[row][coloumn] = 0;
		}
		i++;
	}
	return (0);
}

// check every row and colomn 
int	check_solutions(int sol[4][4], int input[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (what_see(sol[i][0], sol[i][1],
			sol[i][2], sol[i][3]) != input[i + 8])
			return (0);
		if (what_see(sol[i][3], sol[i][2],
			sol[i][1], sol[i][0]) != input[i + 12])
			return (0);
		if (what_see(sol[0][i], sol[1][i],
			sol[2][i], sol[3][i]) != input[i])
			return (0);
		if (what_see(sol[3][i], sol[2][i], sol[1][i],
			sol[0][i]) != input[i + 4])
			return (0);
		i++;
	}
	return (1);
}

// print the solution
void	print_solution(int solution[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = solution[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		if (i != 4)
			write(1, "\n", 1);
		i++;
	}
}

void	fill_zeros(int solution[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			solution[i][j] = 0;
			j++;
		}
		i++;
	}
}
