/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:58 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/12 12:29:19 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static const char	*ft_aff_format(t_printf *ptr, const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	write(1, (char *)format, i);
	ptr->ret += i;
	return (format + i);
}

static int	ft_printf_part_two(t_printf *ptr, va_list params)
{
	if (ptr->conv[ptr->num_conv] != '%')
	{
		ft_conversion(ptr, params);
		if (ptr->ret == -1)
			return (-1);
	}
	else
	{
		int     i;
		char	c;

		c = ' ';
		if (ptr->zero == 1)
			c = '0';
		i = 1;
		if (ptr->minus == -1)
		{
			while (i++ < ptr->field)
				ft_putchar(c);
			ft_putchar('%');
		}
		else
		{
			ft_putchar('%');
			while (i++ < ptr->field)
				ft_putchar(c);
		}
		ptr->ret += i - 1;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		params;
	t_printf	ptr;

	va_start(params, format);
	ptr = (t_printf){FLAGS, -1, -1, -1, -1, -1, CONVERSION, -1, 0, 0};
	while (*format)
	{
		if (*format == '%')
		{
			ptr = (t_printf){FLAGS, -1, -1, -1, -1, -1, CONVERSION,
				-1, 0, ptr.ret};
			format++;
			if (ft_fill_tprintf(&ptr, params, format) == -1)
				return (-1);
			if (ft_printf_part_two(&ptr, params) == -1)
				return (-1);
			format += ptr.len_pat;
		}
		format = ft_aff_format(&ptr, format);
	}
	va_end(params);
	return (ptr.ret);
}
