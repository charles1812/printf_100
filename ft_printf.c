/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:17:47 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/19 19:17:49 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cast(const char format, va_list args)
{	
	int	print_len;

	print_len = 0;
	if (format == 'd')
		print_len += ft_put_nbr(va_arg(args, int));
	else if (format == 'i')
		print_len += ft_put_nbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_put_nbr_u(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_put_nbr_base_min(va_arg(args, unsigned int)) - 1;
	else if (format == 'X')
		print_len += ft_put_nbr_base_max(va_arg(args, unsigned int)) - 1;
	else if (format == 'p')
		print_len += ft_put_pointer_base(va_arg(args, unsigned long));
	else if (format == 's')
		print_len += ft_print_stri(va_arg(args, char *));
	else if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == '%')
		print_len += write (1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_len;
	int		i;	

	i = 0;
	print_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_len += ft_cast(format[i + 1], args);
			i++;
		}
		else
		{
			print_len += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (print_len);
}
