/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:07:43 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/16 20:07:43 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_check_atoi(const char *nbr, const char *base)
{
	int	index;
	int	len_base;

	index = 0;
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] != '+' && nbr[index] != '-'
		&& ft_isinstr(nbr[index], base) == 0)
		return (0);
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	if (ft_isinstr(nbr[index], base) == 0)
		return (0);
	len_base = ft_strlen(base);
	if (len_base < 2 || len_base > 16)
		return (0);
	index = 0;

	return (1);
}

int		ft_atoi_base(const char *nbr, const char *base)
{
	int	index;
	int	nb;
	int	mult;

	index = 0;
	nb = 0;
	mult = 1;
	if (ft_check_atoi(nbr, base) == 0)
		return (ATOI_ERROR);
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	while (ft_isinstr(nbr[index], base) == 1)
		index++;
	index--;
	while (index >= 0 && ft_isinstr(nbr[index], base) == 1)
	{
		nb = (nbr[index] - '0') * mult + nb;
		mult*=10;
		index--;
	}
	if (index >= 0 && nbr[index] == '-')
		return (-nb);
	return (nb);
}