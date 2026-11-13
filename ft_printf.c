/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:47:20 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/13 19:38:02 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_inst(va_list args, const char *str, ...)
{
	int		i;

	i = 0;
	if (str[i] == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if ((str[i] == 'd') || str[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if ((str[i] == 'x') || (str[i] == 'X'))
		return (ft_puthex(str[i], va_arg(args, unsigned int)));
	else if (str[i] == 'p')
		return (ft_point_hex(va_arg(args, void *)));
	else if (str[i] == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		tracker;

	i = 0;
	tracker = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			tracker += ft_print_inst(args, &str[i + 1]);
			i++;
		}
		else
			tracker += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (tracker);
}
