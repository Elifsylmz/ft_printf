/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:32:05 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/08/05 09:36:02 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

int	ft_pointer(void *n)
{
	unsigned long	i;
	int				count;

	count = 0;
	if (!n)
	{
		count += (write(1, "(nil)", 5));
		return (count);
	}
	i = (unsigned long)n;
	count += write(1, "0x", 2);
	count += ft_hex(i, 'x');
	return (count);
}

int	ft_putnbr(int n)
{
	int		len;
	char	c;

	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_unbr(unsigned int num)
{
	int		len;
	char	c;

	len = 0;
	if (num > 9)
		ft_unbr(num / 10);
	c = (num % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_hex(unsigned long n, char c)
{
	char	*use;
	int		len;

	if (c == 'x')
		use = "0123456789abcdef";
	else
		use = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_hex(n / 16, c);
	len += write(1, &use[n % 16], 1);
	return (len);
}
