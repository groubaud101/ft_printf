/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:49 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:49 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	my_c;

	len = ft_strlen(s);
	my_c = (unsigned char)c;
	if (s[len] == my_c)
		return ((char *)s + len);
	while (len--)
		if (s[len] == my_c)
			return ((char *)s + len);
	return (NULL);
}
