/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:47:20 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/06 20:04:16 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_inst(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	if (str[i] == 'c')
		return (ft_putchar(va_arg(args, char)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if ((str[i] == 'd') || (str[i] == 'u'))
		return (ft_putdec(va_arg(args, double)));
	else if ((str[i] == 'x') || (str[i] == 'X'))
		return (ft_puthex(&str[i], va_arg(args, unsigned int)));
	else if (str[i] == 'p')
		return (ft_point_hex(va_args(args, void *)));
	else if (str[i] == '%')
	{
		write (1, '%', 1);
		return (1);
	}
	va_end(args);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_inst(args);
			i++;
		}
		else
			tracker += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (i);
}

int	main()
{
	int ret = ft_printf("Test1: %s %f\n", "testing", 12.345);
	printf("Results: %d\n characters printed", ret);
	return (0);
}