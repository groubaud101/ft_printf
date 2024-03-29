/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulonglong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:11:22 by guroubau          #+#    #+#             */
/*   Updated: 2021/05/28 19:11:22 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_ulonglong_base_fd(unsigned long long n,
								const char *base, int len, int fd)
{
	if (n >= (unsigned long long)len)
		ft_put_ulonglong_base_fd(n / len, base, len, fd);
	ft_putchar_fd(base[ft_abs(n % len)], fd);
}

void	ft_put_ulonglong_base(unsigned long long n, const char *base)
{
	ft_put_ulonglong_base_fd(n, base, ft_strlen(base), 1);
}
