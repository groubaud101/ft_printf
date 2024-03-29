/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:24:28 by guroubau          #+#    #+#             */
/*   Updated: 2021/05/11 15:24:28 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnstr_fd(const char *str, int fd, int n)
{
	int	len;

	if (!str)
		write(fd, "(null)", 6);
	else
	{
		len = ft_strlen(str);
		if (n < len)
			len = n;
		write(fd, str, len);
	}
}
