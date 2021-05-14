/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:22 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:50:17 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** patern : %[flags][field width][precision]conversion
*/

static int	ft_add_flag(t_printf *ptr, const char *format)
{
	int	len;

	len = 0;
	while (format[len] && ft_isinstr(format[len], ptr->flag) >= 0)
	{
		if (format[len] == '-')
			ptr->minus = 1;
		else if (format[len] == '0')
			ptr->zero = 1;
		len++;
	}
	if (ptr->minus == 1)
		ptr->zero = 0;
	return (len);
}

static int	ft_add_field(t_printf *ptr, va_list params, const char *format,
						int len)
{
	if (ft_isdigit(format[len]) == 1 || format[len] == '*')
	{
		if (ft_isdigit(format[len]) == 1)
		{
			ptr->field = ft_atoi(format + len); // comment gere t on l'overflow ?
			while (ft_isdigit(format[len]) == 1)
				len++;
		}
		else
		{
			ptr->field = (int)va_arg(params, int);
			len++;
		}
	}
	return (len);
}

static int	ft_add_precis(t_printf *ptr, va_list params, const char *format,
						int len)
{
	if (format[len] == '.')
	{
		len++;
		ptr->explicit_precis = 0;
		if (format[len] == '*' || ft_isdigit(format[len])) // verifier que l'etoile est explicit
			ptr->explicit_precis = 1;
		if (format[len] == '*')
		{
			ptr->precis = (int)va_arg(params, int);
			len++;
		}
		else
		{
			ptr->precis = ft_atoi(format + len); // comment gere t on l'overflow ?
			while (ft_isdigit(format[len]) == 1)
				len++;			
		}
	}
	return (len);
}

static int	ft_paternlen(t_printf *ptr, va_list params, const char *format)
{
	int	len;

	len = ft_add_flag(ptr, format);

	len = ft_add_field(ptr, params, format, len);

	len = ft_add_precis(ptr, params, format, len);

	ptr->num_conv = ft_isinstr(format[len], ptr->conv);
	if (ptr->num_conv >= 0)
		return (len + 1);
	return (-1);
}


int	ft_fill_tprintf(t_printf *ptr, va_list params, const char *format)
{
	ptr->len_pat = ft_paternlen(ptr, params, format);
	if (ptr->len_pat == -1)
		return (ft_free_tprintf(ptr));

	ptr->patern = ft_strndup(format, ptr->len_pat);
	if (!(ptr->patern))
		return (ft_free_tprintf(ptr));

	ptr->result = ft_conversion(ptr, params);
	if (!(ptr->result))
		return (ft_free_tprintf(ptr));


	return (0);
}
