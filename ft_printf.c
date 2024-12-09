/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdos-rei <tdos-rei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:13:45 by tdos-rei          #+#    #+#             */
/*   Updated: 2024/12/09 11:14:30 by tdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
			count += ft_format(args, ++str);
		else
		{
			write(1, &*str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}

int	ft_format(va_list args, const char *str)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (*str == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		count = ft_printnum(va_arg(args, int), "0123456789", 10);
	else if (*str == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long));
	else if (*str == 'u')
		count = ft_printnum(va_arg(args, unsigned int), "0123456789", 10);
	else if (*str == 'x')
		count = ft_printnum(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (*str == 'X')
		count = ft_printnum(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (*str == '%')
		count = ft_print_char(*str);
	return (count);
}
