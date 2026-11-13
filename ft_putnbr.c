/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:12:39 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/13 18:54:17 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr(long nb)
{
	int		len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_putchar(nb % 10 + '0');
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		len;

	nb = (long)n;
	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
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
	len += ft_printnbr(nb);
	return (len);
}
