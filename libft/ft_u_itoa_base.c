/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:57:41 by guroubau          #+#    #+#             */
/*   Updated: 2021/05/11 18:57:41 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rec_u_itoa_base(unsigned int n, char *nbr, int i, char *base)
{
	if (n > 9)
		nbr = ft_rec_u_itoa_base(n / ft_strlen(base), nbr, i - 1, base);
	nbr[i] = base[n % ft_strlen(base)];
	return (nbr);
}

char	*ft_u_itoa_base(unsigned int n, char *base)
{
	int		len_nbr;
	char	*nbr;

	len_nbr = ft_len_uint_base(n, ft_strlen(base));
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_u_itoa_base(n, nbr, len_nbr - 1, base);
	return (nbr);
}
