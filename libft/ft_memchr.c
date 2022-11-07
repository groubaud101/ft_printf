/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:15 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:15 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*tmp;
	unsigned char	my_c;

	index = 0;
	my_c = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (index < n)
	{
		if (tmp[index] == my_c)
			return ((void *)tmp + index);
		index++;
	}
	return (NULL);
}
