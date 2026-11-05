/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:12:39 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/05 21:25:37 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_putnbr(int nb)
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
