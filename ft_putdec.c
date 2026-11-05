/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:17:51 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/05 21:45:19 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
	if (str[i] == '\0')
	{
		return (0);
	}
}

int	ft_putdec(double dec)
{
	int		integer_part;
	double	fractional_part;
	int		dec_holder;
	int		i;
	char	c;

	integer_part = (int)dec;
	ft_putnbr(dec);
	fractional_part = dec - integer_part;
	i = 0;
	while(i < 6)
	{
		dec *= 10;
		dec_holder = int(dec);
		c = dec_holder + '0';
		write(1, &c, 1);
		i--;
	}
	return(ft_strlen(&c) + 6);
}

int ft_putdec(double dec)
{
    int     count;
    int     i;
    int     digit;
    double  fractional_part;

    count = 0;
    // 1. Handle negative numbers safely
    if (dec < 0)
    {
        write(1, "-", 1);
        dec = -dec;
        count++;
    }
    // 2. Print the integer part
    // (Assuming ft_putnbr prints the int part and returns nothing or handles its own count)
    ft_putnbr((int)dec); 
    
    // Note: If you have a working ft_putnbr_count, add its return value to count.
    // For this example, let's manually track the 7 characters printed below ('.' + 6 digits)
    write(1, ".", 1);
    count++;

    // 3. Isolate the fractional part
    fractional_part = dec - (int)dec;
    i = 0;
    while (i < 6)
    {
        fractional_part *= 10;
        digit = (int)fractional_part;
        
        char c = digit + '0';
        write(1, &c, 1);
        count++;
        
        // Remove the digit we just printed so we can grab the next one
        fractional_part -= digit; 
        i++;
    }
    return (count);
}