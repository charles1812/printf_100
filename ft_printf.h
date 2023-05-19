/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 00:02:41 by cspreafi          #+#    #+#             */
/*   Updated: 2023/04/22 00:02:44 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_cast(const char format, va_list args);
char	*ft_itoa(int n);
int		ft_put_nbr(int format);
void	ft_put_str(char *str);
int		ft_strlen(char *str);
int		ft_print_char(int c);
int		ft_put_nbr_base_max(unsigned int format);
int		ft_put_nbr_base_min(unsigned int format);
char	*ft_itoa_base(unsigned int n, char *base);
char	*ft_itoa_pointer(unsigned long format, char *base);
int		ft_put_pointer_base(unsigned long format);
int		ft_print_stri(char *str);
char	*ft_itoa_u(unsigned int format, char *base);
int		ft_put_nbr_u(unsigned int format);

#endif
