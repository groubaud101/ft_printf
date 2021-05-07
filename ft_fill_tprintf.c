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
#include "./include/ft_printf.h"

/*
** patern : %[flags][field width][precision]conversion
*/

static int	ft_paternlen(char *format, t_printf *ptr)
{
	int	len;

	len = 0;
	while (format[len] && ft_isinstr(format[len], ptr->flag) >= 0)
		len++;
	if (ft_check_patern_flag(format, len, ptr) == 0)
		return (-1);

	ptr->field = 0;
	if (ft_isdigit(format[len]) == 1)
	{
		ptr->field = ft_atoi(format + len); // comment gere t on l'overflow ?
		while (ft_isdigit(format[len]) == 1)
			len++;
	}

	ptr->precis = 0;
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

static int	ft_result_size(char *patern)
{

	return (1);
}

t_printf	*ft_fill_tprintf(t_printf *ptr, char *format)
{
	ptr->len_pat = ft_paternlen(format, ptr);
	if (ptr->len_pat == -1)
	{
		free(ptr);
		return (NULL);
	}

	ptr->patern = ft_strndup(format, ptr->len_pat);
	if (!(ptr->patern))
		return (NULL);




	return (ptr);
}
