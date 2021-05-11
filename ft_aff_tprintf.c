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

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define DEF "\033[0m"

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
	printf(GREEN"result : |%s|\n\n"DEF, ptr->result);
}
