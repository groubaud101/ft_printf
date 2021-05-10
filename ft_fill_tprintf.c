/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:22 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/05 14:04:22 by groubaud         ###   ########.fr       */
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

static int	ft_paternlen(t_printf *ptr, const char *format)
{
	int	len;

	len = ft_add_flag(ptr, format);

	if (ft_isdigit(format[len]) == 1)
	{
		ptr->field = ft_atoi(format + len); // comment gere t on l'overflow ?
		while (ft_isdigit(format[len]) == 1)
			len++;
	}

	if (format[len] == '.')
	{
		len++;
		ptr->precis = ft_atoi(format + len); // comment gere t on l'overflow ?
		while (ft_isdigit(format[len]) == 1)
			len++;
	}

	ptr->num_conv = ft_isinstr(format[len], ptr->conv);
	if (ptr->num_conv >= 0)
		return (len + 1);
	return (-1);
}


t_printf	*ft_fill_tprintf(t_printf *ptr, const char *format)
{
	ptr->len_pat = ft_paternlen(ptr, format);
	if (ptr->len_pat == -1)
	{
		ft_free_tprintf(ptr);
		return (NULL);
	}

	ptr->patern = ft_strndup(format, ptr->len_pat);
	if (!(ptr->patern))
		return (NULL);




	return (ptr);
}
