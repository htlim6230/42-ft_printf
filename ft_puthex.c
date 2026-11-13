/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:40:17 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/13 18:39:38 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(char format, unsigned int n)
{
	int		len;
	char	*base;

	len = 0;

	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
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
		len += ft_putchar(base[n]);
	return (len);
}
