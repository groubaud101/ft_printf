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

// int integerValue = (int) va_arg( parametersInfos, int );

static t_printf	*ft_init_tprintf(t_printf *ptr)
{
	if (ptr == NULL)
	{
		ptr = (t_printf *)malloc(sizeof(t_printf));
		if (!ptr)
			return (NULL);
		ptr->flag = "-0";
		ptr->conv = "cspdiuxX%";
		ptr->ret = 0;
	}
	ptr->minus = -1;
	ptr->zero = -1;
	ptr->field = -1;
	ptr->precis = -1;
	ptr->explicit_precis = -1;
	ptr->num_conv = -1;
	ptr->len_pat = 0;
	return (ptr);
}

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
	t_printf	*ptr;

	va_start(params, format);
	ptr = NULL; // voir si on peut null directement en dessous
	ptr = ft_init_tprintf(ptr);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// printf("f : %c\n", *format);
			ptr = ft_init_tprintf(ptr);
			if (!ptr)
				return (-1);
			if (ft_fill_tprintf(ptr, params, format) == -1)
				return (-1);
			// ft_aff_tprintf(ptr);
			if (ptr->conv[ptr->num_conv] != '%')
			{
				ft_conversion(ptr, params);
				if (ptr->ret == -1) // faudra tester les différentes erreurs, voir si ca continue
					return (-1); // faudra un message d'erreur
			}
			else
			{
				ft_putchar('%');
				ptr->ret++;
			}
			format += ptr->len_pat;
		}
		format = ft_aff_format(ptr, format);
	}
	free(ptr);
	va_end(params);
	return (ptr->ret);
}
