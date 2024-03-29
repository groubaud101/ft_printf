/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:12:39 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/23 17:12:39 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		index = 0;
		while (haystack[index] == needle[index] && needle[index])
			index++;
		if (needle[index] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
