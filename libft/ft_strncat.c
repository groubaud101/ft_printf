/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:09:21 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/23 17:09:21 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = 0;
	while (src[s] && s < n)
	{
		dst[d++] = src[s++];
	}
	dst[d] = '\0';
	return (dst);
}
