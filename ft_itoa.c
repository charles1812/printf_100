/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:46:15 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/24 14:46:16 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	test(unsigned int j, int i)
{
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

char	*ft_piece(char *res, int i, unsigned int j)
{
	while (i >= 0 && j > 0)
	{
		res[i--] = (j % 10) + 48;
		j = j / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	char			*res;

	i = 0;
	if (n < 0 && i++ == 0)
		j = n * -1;
	else
		j = n;
	i = test(j, i);
	if (j == 0)
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	if (j == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[i--] = '\0';
	res = ft_piece(res, i, j);
	return (res);
}
