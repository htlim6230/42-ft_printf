/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:43:02 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/06 20:04:18 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

#include <stdio.h>

int	ft_point_hex(void *n)
{
	long	nb;
	int		i;
	int		len;
	char	*base;

	len = 0;
	n = nb;
	base = "0123456789abcdef";
	while (nb[i] != '\0')
	{
		if (nb >= 16)
		{
			len += ft_puthex('x', nb / 16);
			len += ft_puthex('x', nb % 16);
		}
		else
		{
			len += ft_putchar(base[nb]);
		}
		i++;
	}
	return (len);
}
