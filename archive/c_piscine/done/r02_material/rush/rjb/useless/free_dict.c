/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhoder <abkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:00:52 by abkhoder          #+#    #+#             */
/*   Updated: 2025/04/27 16:04:42 by abkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"

void	free_dict(Dictentry *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(dict[i].value);
		i++;
	}
	free(dict);
}
