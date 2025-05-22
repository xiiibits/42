/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhoder <abkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 23:55:35 by abkhoder          #+#    #+#             */
/*   Updated: 2025/04/27 16:06:07 by abkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "dict.h"

int	parse_dict(Dictentry **dict, char *filename, int max_nb)
{
	int	fd;
	int	i;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
		return (0);
	*dict = malloc(max_nb * sizeof(Dictentry));
	i = 0;
	while (i < max_nb)
	{
		(*dict)[i].key = i;
		(*dict)[i].value = malloc(10);
		i++;
	}
	close (fd);
	return (i);
}
