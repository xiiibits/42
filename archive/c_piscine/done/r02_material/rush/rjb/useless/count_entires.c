/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_entires.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:31:06 by abkhoder          #+#    #+#             */
/*   Updated: 2025/04/27 21:40:59 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "dict.h"

int	count_entries(char *filename)
{
	int		fd;
	char	character[1024];
	int		bytes;
	int		count;
	int		in_line;

	count = 0;
	in_line = 0;
	fd = open(filename, O_RDONLY);
	bytes = read(fd, character, 1024);
	while (bytes > 0)
	{
		while (bytes--)
		{
			if (character[bytes] == '\n' && in_line)
				count++;
			in_line = (character[bytes] != '\n');
		}
		close(fd);
		return (count);
	}
}
