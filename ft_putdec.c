/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:17:51 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/06 17:33:44 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

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

int	ft_put_fraction(double fractional_part)
{
	int		digit;
	int		i;
	char	c;

	i = 0;
	while (i < 6)
	{
		fractional_part *= 10;
		digit = (int)fractional_part;
		c = digit + '0';
		write(1, &c, 1);
		fractional_part -= digit;
		i++;
	}
	return (6);
}

int	ft_putdec(double dec)
{
	int		count;
	double	fractional_part;

	count = 0;

	if (dec < 0)
	{
		write(1, "-", 1);
		dec = -dec;
		count++;
	}
	ft_putnbr((int)dec);
	write(1, ".", 1);
	count++;
	fractional_part = dec - (int)dec;
	count += ft_put_fraction(fractional_part);
	return (count);
}
