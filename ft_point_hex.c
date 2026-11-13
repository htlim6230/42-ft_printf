/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:43:02 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/13 18:39:15 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer(unsigned long long nb)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		len += ft_pointer(nb / 16);
		len += ft_pointer(nb % 16);
	}
	else
		len += ft_putchar(base[nb]);
	return (len);
}

int	ft_point_hex(void *n)
{
	unsigned long long	nb;
	int					len;

	len = 0;
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	nb = (unsigned long long)n;
	len += ft_pointer(nb);
	return (len + 2);
}
