/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:38:44 by afahs             #+#    #+#             */
/*   Updated: 2025/04/20 17:00:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks what the group apear
int	what_see(int i, int ii, int iii, int iv)
{
	int	j;
	int	max;
	int	count;
	int	group[4];

	group[0] = i;
	group[1] = ii;
	group[2] = iii;
	group[3] = iv;
	j = 0;
	max = 0;
	count = 0;
	while (j < 4)
	{
		if (group[j] > max)
		{
			max = group[j];
			count++;
		}
		j++;
	}
	return (count);
}

// check if the place to change the integer is valid
int	can_put(int sol[4][4], int row, int coloumn, int n)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (sol[row][i] == n || sol[i][coloumn] == n)
			return (0);
		i++;
	}
	return (1);
}

// check if the input is valid
int	is_valid(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (i % 2 == 0 && (input[i] > '4' || input[i] < '1'))
			return (0);
		if (i % 2 != 0 && input[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

//change the input from string to integer
int	*stoi(char *string_input, int int_input[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (string_input[i])
	{
		if (string_input[i] <= '4' && string_input[i] >= '1')
		{
			int_input[j] = string_input[i] - '0';
			j++;
		}
		i++;
	}
	return (int_input);
}
