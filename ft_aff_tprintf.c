/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff_tprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:30:36 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/10 15:30:36 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_aff_tprintf(t_printf *ptr)
{
	if (!ptr)
	{
		printf("ptr NULL\n");
		return ;
	}
	printf("const flag : |%s|\n", ptr->flag);
	printf("const conv : |%s|\n", ptr->conv);
	printf("num conv : %i (%c)\n", ptr->num_conv, ptr->conv[ptr->num_conv]);
	printf("patern : |%s|\n", ptr->patern);
	printf("len_pat : %i\n", ptr->len_pat);
	printf("minus : %i\n", ptr->minus);
	printf("zero : %i\n", ptr->zero);
	printf(BLUE"field : %i\n"DEF, ptr->field);
	printf(RED"precis : %i\n"DEF, ptr->precis);
	printf(GREEN"result : |%s|\n"DEF"\n", ptr->result);
}
