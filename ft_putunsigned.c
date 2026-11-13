/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:22:27 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/13 19:19:52 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printunsigned(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_printunsigned(nb / 10);
		len += ft_putchar(nb % 10 + '0');
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	unsigned long	nb;
	int				len;

	nb = (unsigned long)n;
	len = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len++;
	}
	len += ft_printunsigned(nb);
	return (len);
}
