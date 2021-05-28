/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:13:22 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 21:13:22 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_conv_c(t_printf *ptr, va_list params) // à tester, c = 0
{
	char	c;
	int		i;

	c = (unsigned char)va_arg(params, int);
	i = 1;
	while (i++ < ptr->field)
		ft_putchar(' ');
	ft_put_uchar(c);
	ptr->ret += i;
	return (1);
}

static int	ft_conv_s(t_printf *ptr, va_list params)
{
	const char	*str;
	int			len;
	int			i;

	str = (const char *)va_arg(params, const char *);
	if (ptr->field > -1 && ptr->precis == -1)
	{
		i = ptr->field;
		len = ft_strlen(str);
		while (i++ < len)
			ft_putchar(' ');
		ptr->ret += len + (i - ptr->field);
		write(1, str, len);
	}
	else if (ptr->field > -1 && ptr->precis > -1)
	{
		i = ptr->field;
		len = ft_the_min(2, ft_strlen(str), ptr->precis);
		while (i++ < len)
			ft_putchar(' ');
		ptr->ret += len + (i - ptr->field);
		write(1, str, len);
	}
	else if (ptr->precis > -1)
	{
		len = ft_the_min(2, ft_strlen(str), ptr->precis);
		ft_putnstr(str, len); // tester une chaine null
		ptr->ret += len;
	}
	else
	{
		ft_putstr((char *)str);
		ptr->ret += ft_strlen(str);
	}
	return (1);
}

static int	ft_conv_p(t_printf *ptr, va_list params) // penser qu'un ptr null affiche (nil)
{
	unsigned long long	nb;
	const char			*base;

	base = "0123456789abcdef";
	nb = (unsigned long long)va_arg(params, void *);
	if (ptr->zero == 1)
	{
		ptr->ret += ft_aff_p(ptr, ft_len_ulonglong_base(nb, 16) + 2, nb);
	}
	else
	{
		ft_putstr("0x");
		ft_put_ulonglong_base(nb, base);
		ptr->ret += ft_aff_p(ptr, ft_len_ulonglong_base(nb, 16) + 2, nb);
	}
	return (1);
}

int 	ft_conversion(t_printf *ptr, va_list params)
{
	int	(*tab[9])(t_printf *ptr, va_list params);

	tab[0] = &ft_conv_c;
	tab[1] = &ft_conv_s;
	tab[2] = &ft_conv_p;
	tab[3] = &ft_conv_di;
	tab[4] = &ft_conv_di;
	tab[5] = &ft_conv_u;
	tab[6] = &ft_conv_x;
	tab[7] = &ft_conv_xup;

	return (tab[ptr->num_conv](ptr, params));
}
