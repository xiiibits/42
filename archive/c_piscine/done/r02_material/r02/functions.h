/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamas <mchamas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:27:50 by afahs             #+#    #+#             */
/*   Updated: 2025/04/27 23:38:06 by mchamas          ###   ########.fr       */
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
int		ft_str_is_alpha(char *str);
void	correct_string(char *str);
char	*word(char *str, char *charset);
char	**helper(char **splitted, int j);
char	**ft_split(char *str, char *charset);
char	*put_dic_in_string(char *dicname);
int		is_sep(char c, char *charset);
int		count_words(char *str, char *charset);
void	fill_the_first(char **arr, char *file);
char	*ft_strcpy(char *dest, char *src);
void	fill_tens(char **tens);
void	fill_extra(char **extra);
void	fill_ones(char **ones);

#endif
