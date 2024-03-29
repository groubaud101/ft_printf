/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:06:59 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/23 17:06:59 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = 0;
	while (src[s])
		dst[d++] = src[s++];
	dst[d] = '\0';
	return (dst);
}
