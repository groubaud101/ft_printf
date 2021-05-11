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
	ptr->num_conv = -1;
	ptr->patern = NULL;
	ptr->len_pat = -1;
	ptr->result = NULL;
	ptr->len_res = -1;
	return (ptr);
}

int	ft_printf(const char *format, ...)
{
	va_list 	params;
	t_printf	*ptr;

	va_start(params, format);
	ptr = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ptr = ft_init_tprintf(ptr);
			if (!ptr)
				return (0);
			ptr = ft_fill_tprintf(ptr, params, format);
			if (!ptr)
				return (0);

			// affichage du result
			
			if (ptr->conv[ptr->num_conv] != '%')
			{
				ft_putstr(ptr->result);
				// ft_aff_tprintf(ptr);
			}
			else
				ft_putchar('%');
			format+=ptr->len_pat;

		}
		ft_putchar(*format);
		format++;
	}
	return (1);
}