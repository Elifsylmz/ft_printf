/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:31:53 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/08/03 19:31:57 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find(char c, va_list args)
{
	if(c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if(c == 'p')
		return(ft_pointer(va_arg(args, void *)));
	else if(c == 'd' || c == 'i')
		return(ft_putnbr(va_arg(args, int)));
	else if(c == 'u')
		return(ft_unbr(va_arg(args, unsigned int)));
	else if(c == 'x' || c == 'X')
		return(ft_hex(va_arg(args, unsigned int), c));
	else if(c == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	if(!format)
		return (0);
	count = 0;
	i = 0;
	va_start(args, format);
	 while (format[i])
	 {
		if(format[i] != '%')
		{
			count += write(1,&format[i],1);
		}
		else
		{
			count += find(format[i+1],args);
		}
		i++;
	 }
	 va_end(args);
	 return (count);
}
