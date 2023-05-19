/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:05:45 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/25 18:05:53 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_put_str(char *str)
{
	write (1, str, ft_strlen(str));
}

int	ft_print_stri(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_put_str("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}
