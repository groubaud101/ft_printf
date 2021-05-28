/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:56:25 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 18:56:25 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_put_uint_base_fd(unsigned int n, const char *base, int len,
									int fd)
{
	if (n >= len || n <= -len)
		ft_rec_put_uint_base_fd(n / len, base, len, fd);
	if (n > -len && n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(base[ft_abs(n % len)] + '0', fd);
}

void	ft_put_uint_base_fd(unsigned int n, const char *base, int fd)
{
	ft_rec_put_uint_base_fd(n, base, ft_strlen(base), fd);
}
