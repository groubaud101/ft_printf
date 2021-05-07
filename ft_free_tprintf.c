/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:03:21 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/07 20:03:21 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_free_tprintf(t_printf *ptr)
{
	if (ptr)
	{
		if (ptr->patern)
			free(ptr->patern);
		if (ptr->result)
			free(ptr->result);
		free(ptr)
	}
	return (0);
}