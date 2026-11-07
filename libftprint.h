/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:36:27 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/06 17:42:30 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#infdef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_put_fraction(double fractional_part);
int		ft_putdec(double dec);
int		ft_puthex(char format, unsigned int n);
int		ft_putnbr(int n);
int		ft_point_hex(void *n);

#endif