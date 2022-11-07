/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:23:28 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/01 17:23:28 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*tmp;

	index = 0;
	tmp = (char *)s;
	while (index < n)
	{
		tmp[index] = '\0';
		index++;
	}
	s = (void *)tmp;
}
