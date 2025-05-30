/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:18:52 by afahs             #+#    #+#             */
/*   Updated: 2025/05/30 11:16:08 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(char *c)
{
	if (!c)
		return (write(1, "(null)", 6));
	return (write(1, c, ft_strlen(c)));
}

static int	ft_putptr(void *n)
{
	int	count;

	count = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putp((unsigned long) n);
	return (count);
}

static int	print_form(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(arg, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_putbase(va_arg(arg, unsigned int), "0123456789"));
	else if (c == 'X')
		return (ft_putbase(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_putbase(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *c, ...)
{
	va_list	arg;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(arg, c);
	while (c[i])
	{
		if (c[i] != '%')
			counter += write(1, &c[i], 1);
		else if (c[i + 1])
		{
			counter += print_form(c[i + 1], arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (counter);
}
