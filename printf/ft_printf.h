/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:02:21 by afahs             #+#    #+#             */
/*   Updated: 2025/05/30 10:53:26 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *c, ...);
int				ft_putnbr(int n);
int				ft_putbase(unsigned int n, char *base);
int				ft_putp(unsigned long n);
int				ft_putchar(char c);
unsigned int	ft_strlen(const char *s);

#endif