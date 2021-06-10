/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:58 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:49:36 by groubaud         ###   ########.fr       */
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
	// printf("i : %i\n", i);
	write(1, (char *)format, i);
	ptr->ret += i;
	// printf("format : %s\n", format + i);
	return (format + i);
}

int	ft_printf(const char *format, ...)
{
	va_list 	params;
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
			// ft_aff_tprintf(&ptr);
			if (ptr.conv[ptr.num_conv] != '%')
			{
				ft_conversion(&ptr, params);
				if (ptr.ret == -1) // faudra tester les différentes erreurs, voir si ca continue
					return (-1); // faudra un message d'erreur
			}
			else
			{
				ft_putchar('%');
				ptr.ret++;
			}
			format += ptr.len_pat;
		}
		format = ft_aff_format(&ptr, format);
	}
	va_end(params);
	return (ptr.ret);
}