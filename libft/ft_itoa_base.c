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

static char	*ft_rec_itoa_base(int n, char *nbr, int i, char *base)
{
	if (n > 9 || n < -9)
		nbr = ft_rec_itoa_base(n / ft_strlen(base), nbr, i - 1, base);
	nbr[i] = base[ft_abs(n % ft_strlen(base))];
	return (nbr);
}

char	*ft_itoa_base(int n, char *base)
{
	int		len_nbr;
	char	*nbr;

	len_nbr = ft_len_int_base(n, ft_strlen(base));
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_itoa_base(n, nbr, len_nbr - 1, base);
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
