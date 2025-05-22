/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhoder <abkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:47:19 by abkhoder          #+#    #+#             */
/*   Updated: 2025/04/27 16:06:46 by abkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dict_h
# define Dict_h

typedef	struct s_dict
{
	int	key;
	char	*value;
}	Dictentry;

int	ft_atoi(char *str);
void	ft_putstr(char *str);
int	count_entries(char *filename);
int	parse_dict(Dictentry **dict, char *filename, int max_nb);
void	free_dict(Dictentry *dict, int size);
int	is_valid_number(char *str);
# endif;
