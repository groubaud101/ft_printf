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
#include <stdarg.h>
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
	int	i = 0;

	va_start(params, format);
	ptr = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printf("caractere %i : %c\n", i++, *format);
			ptr = ft_init_tprintf(ptr);
			if (!ptr)
				return (0);
			ptr = ft_fill_tprintf(ptr, format);
			if (!ptr)
				return (0);
			// ifs pour le type et redirection (what_is_your_kind)

			// remplissage du result

			// affichage du result
			if (ptr->conv[ptr->num_conv] != '%')
			{
				ft_putchar('\n');
				ft_aff_tprintf(ptr);
			}
			else
				ft_putchar('%');

			// if (*format == 'i')
			// {
			// 	int integerValue = (int)va_arg( params, int);
			// 	ft_putnbr(integerValue);
			// }
			// else if (*format == 's')
			// {
			// 	char *str = (char *)va_arg(params, char *);
			// 	ft_putstr(str);
			// }
			// else if (*format == 'c')
			// {
			// 	char c = (unsigned char)va_arg(params, int);
			// 	ft_putchar(c);
			// }
			format+=ptr->len_pat;

		}
		// ft_putchar(*format);
		format++;
	}
	return (1);
}