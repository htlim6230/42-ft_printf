#include <stdarg.h>
#include "ft_printf.h"

int	ft_printunsigned(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb>=10)
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
	int		len;

	nb = (unsigned long)n;
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
	len += ft_printunsigned(nb); 
	return (len);
}