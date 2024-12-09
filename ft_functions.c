/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdos-rei <tdos-rei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:13:48 by tdos-rei          #+#    #+#             */
/*   Updated: 2024/12/09 11:15:56 by tdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_printnum(long n, char *base, int len)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= len)
		count += ft_printnum(n / len, base, len);
	write(1, &base[n % len], 1);
	count++;
	return (count);
}

int	ft_print_pointer(unsigned long p)
{
	int	count;

	count = 2;
	if (!p)
		return (ft_printf("(nil)"));
	ft_printf("0x");
	if (p >= 16)
		count += ft_printnum(p / 16, "0123456789abcdef", 16);
	write(1, &"0123456789abcdef"[p % 16], 1);
	count++;
	return (count);
}
