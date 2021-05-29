/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diuxx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:11:37 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 21:11:37 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_di(t_printf *ptr, va_list params)
{
	int			nb;
	const char	*base;

	base = "0123456789";
	nb = (int)va_arg(params, int);
	if (ptr->zero == 1 || ptr->precis > -1)
	{
		ptr->ret += ft_aff_diuxx(ptr, ft_len_int_base(nb, 10));
		ft_put_int_base(nb, base, 10);
	}
	else
	{
		ft_put_int_base(nb, base, 10);
		ptr->ret += ft_aff_diuxx(ptr, ft_len_int_base(nb, 10));
	}
	return (1);
}

int	ft_conv_u(t_printf *ptr, va_list params)
{
	unsigned int	nb;
	const char		*base;

	base = "0123456789";
	nb = (unsigned int)va_arg(params, unsigned int);
	if (ptr->zero == 1)
	{
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 10));
		ft_put_uint_base(nb, base, 10);
	}
	else
	{
		ft_put_uint_base(nb, base, 10);
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 10));
	}
	return (1);
}

int	ft_conv_x(t_printf *ptr, va_list params)
{
	unsigned int	nb;
	const char		*base;

	base = "0123456789abcdef";
	nb = (unsigned int)va_arg(params, unsigned int);
	if (ptr->zero == 1)
	{
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 16));
		ft_put_uint_base(nb, base, 16);
	}
	else
	{
		ft_put_uint_base(nb, base, 16);
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 16));
	}
	return (1);
}

int	ft_conv_xup(t_printf *ptr, va_list params)
{
	unsigned int	nb;
	const char		*base;

	base = "0123456789ABCDEF";
	nb = (unsigned int)va_arg(params, unsigned int);
	if (ptr->zero == 1)
	{
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 16));
		ft_put_uint_base(nb, base, 16);
	}
	else
	{
		ft_put_uint_base(nb, base, 16);
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 16));
	}
	return (1);
}