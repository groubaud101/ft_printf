/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:23:47 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:23:47 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_this_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static char	*ft_rec_itoa(int n, char *nbr, int i)
{
	if (n > 9 || n < -9)
		nbr = ft_rec_itoa(n / 10, nbr, i - 1);
	nbr[i] = ft_this_abs(n % 10) + '0';
	return (nbr);
}

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len_nbr;
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	len_nbr = ft_nbrlen(n);
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_itoa(n, nbr, len_nbr - 1);
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
