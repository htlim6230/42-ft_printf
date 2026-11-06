/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:40:17 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/06 17:33:47 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

#include <stdio.h>

int	ft_puthex(char format, unsigned int n)
{
	// long	nb;
	int		len;
	char	*base;

	// nb = n;
	len = 0;

	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_puthex(format, n / 16);
		len += ft_puthex(format, n % 16);
	}
	else
	{
		len += ft_putchar(base[n]);
	}
	return (len);
}