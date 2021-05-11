/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:58 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/29 13:03:59 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

// int integerValue = (int) va_arg( parametersInfos, int );

static t_printf	*ft_init_tprintf(t_printf *ptr)
{
	if (ptr == NULL)
	{
		ptr = (t_printf *)malloc(sizeof(*ptr));
		if (!ptr)
			return (NULL);
		ptr->flag = "-0";
		ptr->conv = "cspdiuxX%";
	}
	else
	{
		if (ptr->patern)
			free(ptr->patern);
		if (ptr->result)
			free(ptr->result);
	}
	ptr->minus = -1;
	ptr->zero = -1;
	ptr->field = -1;
	ptr->precis = -1;
	ptr->explicit_precis = -1;
	ptr->num_conv = -1;
	ptr->patern = NULL;
	ptr->len_pat = -1;
	ptr->result = NULL;
	ptr->len_res = -1;
	return (ptr);
}

static const char	*ft_aff_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	ft_putnstr((char *)format, i);
	return (format + i);
}

int	ft_printf(const char *format, ...)
{
	va_list 	params;
	t_printf	*ptr;
	int			ret;

	va_start(params, format);
	ptr = NULL;
	ret = ft_strlen(format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ptr = ft_init_tprintf(ptr);
			if (!ptr)
				return (-1);
			ptr = ft_fill_tprintf(ptr, params, format);
			if (!ptr)
				return (-1);

			// affichage du result + count du nb de catactere affiché
			if (ptr->conv[ptr->num_conv] != '%')
			{
				// ret = ft_aff_result(ptr);
				ft_putstr(ptr->result);
				// ft_aff_tprintf(ptr);
			}
			else
				ft_putchar('%');
			ret = ret - (ptr->len_pat + 1) + ft_strlen(ptr->result);

			format += ptr->len_pat;
		}
		format = ft_aff_format(format);
	}
	return (ret);
}