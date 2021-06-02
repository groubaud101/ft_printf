/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:07:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/16 20:07:27 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rec_itoa_base(int n, char *nbr, int i, char *base, int len_base)
{
	if (n >= len_base || n <= -len_base)
		nbr = ft_rec_itoa_base(n / len_base, nbr, i - 1, base, len_base);
	nbr[i] = base[ft_abs(n % len_base)];
	return (nbr);
}

char	*ft_itoa_base(int n, char *base)
{
	int		len_nbr;
	char	*nbr;
	int		len_base;

	len_base = ft_strlen(base);
	len_nbr = ft_len_int_base(n, len_base);
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_itoa_base(n, nbr, len_nbr - 1, base, len_base);
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
