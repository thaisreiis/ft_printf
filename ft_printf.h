/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdos-rei <tdos-rei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:13:58 by tdos-rei          #+#    #+#             */
/*   Updated: 2024/12/09 09:32:51 by tdos-rei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list args, const char *str);
int	ft_print_char(char c);
int	ft_print_str(const char *str);
int	ft_printnum(long n, char *base, int len);
int	ft_print_pointer(unsigned long p);

#endif