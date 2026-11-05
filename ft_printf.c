/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:47:20 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/05 21:43:25 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
//#include "ft_printf.h"

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
	if (str[i] == '\0')
	{
		return (0);
	}
}

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

int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len++;
	}
	if (nb >= 10)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putchar(nb % 10 + '0');
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putdec(double dec)
{
	int		integer_part;
	double	fractional_part;
	int		dec_holder;
	int		i;
	char	c;

	integer_part = (int)dec;
	ft_putnbr(dec);
	fractional_part = dec - integer_part;
	i = 0;
	while(i < 6)
	{
		dec *= 10;
		dec_holder = (int)dec;
		c = dec_holder + '0';
		write(1, &c, 1);
		i--;
	}
	return(ft_strlen(&c) + 6);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tracker;
	int		i;
	int		n;
	char	c;
	char	*s;
	int	nb;
	double	dec;

	i = 0;
	n = 0;
	tracker = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			i++;
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			tracker++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			i++;
			s = va_arg(args, char*);
			tracker += ft_putstr(s);
		}
		else if (str[i] == '%' && (str[i + 1] == 'i'))
		{
			i++;
			nb = va_arg(args, int);
			tracker += ft_putnbr(nb);
		}
		else if (str[i] == '%' && (str[i + 1] == 'd'))
		{
			i++;
			dec = va_arg(args, double);
			tracker += ft_putdec(nb);
		}
		else
		{
			tracker += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (tracker);
}

int	main()
{
	int ret = ft_printf("Test1: %s %f\n", "testing", 12.345);
	printf("Results: %d\n characters printed", ret);
	return (0);
}