/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:27:50 by afahs             #+#    #+#             */
/*   Updated: 2025/04/27 21:52:30 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_arrlen(char **num);
int		get_num_of_segmants_from_char(char *c);
void	reverse_string(char *str);
char	*fill_three(int i, char *str);
char	**segmentation(char *str);
int		*stoi(char *s);
void	print_single_segment(int *nb, char ***dic);
void	print_the_holy_number(char **nums, char ***dic);
void	fill_array(char **ones, char **tens, char **extra);

#endif
