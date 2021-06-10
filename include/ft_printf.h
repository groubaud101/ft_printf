/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:38:43 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/10 19:38:43 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "0-"
# define CONVERSION "cspdiuxX%"

# include "libft.h"
# include "ft_colors.h"
# include <stdarg.h>

#include <stdio.h>

/*
**     conv : c s p d i u x X %
** num_conv : 0 1 2 3 4 5 6 7 8
*/

typedef struct	s_printf
{
	char	*flag;
	int		minus;
	int		zero;
	int		field;
	int		precis;
	int		explicit_precis;
	char	*conv;
	int		num_conv;
	int		len_pat;
	int		ret;
}t_printf;

void	ft_aff_tprintf(t_printf *ptr);

int		ft_printf(const char *format, ...);
int		ft_fill_tprintf(t_printf *ptr, va_list params, const char *format);
int		ft_free_tprintf(t_printf *ptr);

int		ft_conversion(t_printf *ptr, va_list params);
int		ft_aff_di(t_printf *ptr, int len, int neg);
int		ft_aff_diuxx(t_printf *ptr, int len);
int		ft_aff_p(t_printf *ptr, int len, unsigned long long n);
int		ft_aff_s(t_printf *ptr, const char *str);
int		ft_conv_di(t_printf *ptr, va_list params);
int		ft_conv_u(t_printf *ptr, va_list params);
int		ft_conv_x(t_printf *ptr, va_list params);
int		ft_conv_xup(t_printf *ptr, va_list params);

#endif
