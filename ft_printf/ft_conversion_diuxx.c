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
	int				nb;
	unsigned int	nb2;
	int			len;
	const char	*base;

	base = "0123456789";
	nb = (int)va_arg(params, int);
	nb2 = ft_abs(nb);
	len = ft_the_max(2, ft_len_uint_base(nb2, 10), ptr->precis) + (nb < 0)
			- (nb == 0 && ptr->precis == 0);
	if (ptr->minus != 1)
	{
		if (ptr->zero == 1)
		{
			if (nb < 0)
				ft_putchar('-');
			while (ptr->field > len++)
			{
				ft_putchar('0');
			}
		}
		else
		{
			while (ptr->field > len++)
			{
				ft_putchar(' ');
			}
			if (nb < 0)
				ft_putchar('-');
		}
	}
	len = ft_len_uint_base(nb2, 10) - (nb == 0 && ptr->precis == 0);
	while (ptr->precis > len++)
		ft_putchar('0');
	if (ptr->minus == 1 && nb < 0)
		ft_putchar('-');
	if (!(ptr->precis == 0 && nb == 0))
		ft_put_uint_base(nb2, base);
	else if (ptr->field <= 0)
		ptr->ret--;
	len = ft_the_max(2, ft_len_uint_base(nb2, 10), ptr->precis) + (nb < 0);
	if (nb == 0 && ptr->precis == 0)
		len = 0;
	if (ptr->minus == 1)
	{
		while (ptr->field > len++)
		{
			ft_putchar(' ');
		}
	}
	ptr->ret += ft_the_max(3, ptr->field, ptr->precis + (nb < 0),
						ft_len_int_base(nb, 10));
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
		ft_put_uint_base(nb, base);
	}
	else
	{
		ft_put_uint_base(nb, base);
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
		ft_put_uint_base(nb, base);
	}
	else
	{
		ft_put_uint_base(nb, base);
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
		ft_put_uint_base(nb, base);
	}
	else
	{
		ft_put_uint_base(nb, base);
		ptr->ret += ft_aff_diuxx(ptr, ft_len_uint_base(nb, 16));
	}
	return (1);
}