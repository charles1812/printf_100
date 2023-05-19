/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:23:27 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/24 15:23:29 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int format)
{
	char	len;
	char	*str;

	str = ft_itoa(format);
	len = ft_print_stri(str);
	free(str);
	return (len);
}

int	ft_put_nbr_base_min(unsigned int format)
{
	int		len;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	str = ft_itoa_base(format, base);
	len = ft_print_stri(str) + 1;
	free(str);
	return (len);
}

int	ft_put_nbr_base_max(unsigned int format)
{
	int		len;
	char	*str;
	char	*base;

	base = "0123456789ABCDEF";
	str = ft_itoa_base(format, base);
	len = ft_print_stri(str) + 1;
	free(str);
	return (len);
}

int	ft_put_pointer_base(unsigned long format)
{
	int		len;
	char	*str;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	str = ft_itoa_pointer(format, base);
	if (str[0] == '\0')
	{
		free(str);
		len += ft_print_stri("(nil)");
		return (len);
	}
	else
	{
		write (1, "0x", 2);
		len += 2;
	}
	len += ft_print_stri(str);
	free(str);
	return (len);
}

int	ft_put_nbr_u(unsigned int format)
{
	int		len;
	char	*str;
	char	*base;

	base = "0123456789abcdef";
	str = ft_itoa_u(format, base);
	len = ft_print_stri(str);
	free(str);
	return (len);
}
