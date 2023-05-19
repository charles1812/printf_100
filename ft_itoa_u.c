/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:33:16 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/24 17:33:18 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	test_u(unsigned int format, int index)
{
	if (format == 0)
		return (1);
	while (format != 0)
	{
		format = format / 10;
		index++;
	}
	return (index);
}

char	*ft_piece_u(char *result, int index, unsigned int format, char *base)
{
	while (index >= 0 && format > 0)
	{
		result[index--] = base[format % 10];
		format = format / 10;
	}
	return (result);
}

char	*ft_itoa_u(unsigned int format, char *base)
{
	int				index;
	char			*result;

	index = 0;
	index = test_u(format, index);
	result = malloc(sizeof(char) * index + 1);
	if (!result)
		return (NULL);
	if (format == 0)
		result[0] = '0';
	result[index] = '\0';
	if (index != 0)
		result = ft_piece_u(result, index - 1, format, base);
	return (result);
}
