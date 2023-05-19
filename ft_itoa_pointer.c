/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:34 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/24 16:48:36 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	test_base(unsigned long format, int index)
{
	while (format != 0)
	{
		format = format / 16;
		index++;
	}
	return (index);
}

char	*ft_piece_p(char *result, int index, unsigned long format, char *base)
{
	while (index >= 0 && format > 0)
	{
		result[index--] = base[format % 16];
		format = format / 16;
	}
	return (result);
}

char	*ft_itoa_pointer(unsigned long format, char *base)
{
	int				index;
	char			*result;

	index = 0;
	index = test_base(format, index);
	result = malloc(sizeof(char) * index + 1);
	if (!result)
		return (NULL);
	if (format == 0)
		result[0] = '0';
	result[index] = '\0';
	if (index != 0)
		result = ft_piece_p(result, index - 1, format, base);
	return (result);
}
