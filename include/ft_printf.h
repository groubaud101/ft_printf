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
	char	*patern;
	int		len_pat;
	char	*result;
	int		len_res;
}t_printf;

void		ft_aff_tprintf(t_printf *ptr);

int			ft_printf(const char *format, ...);
t_printf	*ft_fill_tprintf(t_printf *ptr, va_list params, const char *format);
int			ft_free_tprintf(t_printf *ptr);
char 		*ft_conversion(t_printf *ptr, va_list params);

#endif
