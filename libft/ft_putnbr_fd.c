/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guroubau <guroubau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:28 by guroubau          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:28 by guroubau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= -9 && n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(ft_abs(n % 10) + '0', fd);
}
