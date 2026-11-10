/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 21:58:07 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/10/28 14:52:58 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_put_fraction(double fractional_part);
int		ft_putdec(double dec);
int		ft_puthex(char format, unsigned int n);
int	    ft_printnbr(long nb);
int		ft_putnbr(int n);
int		ft_point_hex(void *n);

#endif
