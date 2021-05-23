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
#include <stdlib.h>

int	ft_free_tprintf(t_printf *ptr)
{
	if (ptr)
	{
		if (ptr->patern)
		{
			//free(ptr->patern);
			ptr->patern = NULL;
		}
		if (ptr->result)
		{
			//free(ptr->result);
			ptr->result = NULL;	
		}
		//free(ptr);
		ptr = NULL;
	}
	return (-1);
}