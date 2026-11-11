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
	int		len;

	len = 0;
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	nb = (long)n;
	write (1, "0x", 2);
	len += (ft_puthex('x', nb);
	return (len + 2);
}
