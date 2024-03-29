/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:23:33 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/01 17:23:33 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	index;
	size_t	mult;

	index = 0;
	mult = nmemb * size;
	array = (char *)malloc(mult);
	if (array == NULL)
		return (NULL);
	while (index < mult)
		array[index++] = 0;
	return ((void *)array);
}
