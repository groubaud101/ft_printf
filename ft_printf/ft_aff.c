/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:48:14 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 19:48:14 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

 int	ft_aff_diuxx(t_printf *ptr, int len)
 {
	int		i;
	char	c;

	c = ' ';
	if (ptr->zero == 1 || ptr->precis > -1)
		c = '0';
	i = ptr->precis;
	if (i < ptr->field)
	 	i = ptr->field;
	while (i > 0 && i-- > len)
		ft_putchar(c);
	return (ft_the_max(3, ptr->precis, ptr->field, len));
 }

 int	ft_aff_p(t_printf *ptr, int len, unsigned long long n)
 {
	int		i;
	char	c;

	c = ' ';
	if (ptr->zero == 1 || ptr->precis > -1)
		c = '0';
	if (ptr->zero == 1)
		ft_putstr("0x");
	i = ptr->precis;
	if (i < ptr->field)
	 	i = ptr->field;
	while (i > 0 && i++ < len)
		ft_putchar(c);
	if (ptr->zero == 1)
		ft_put_ulonglong_base(n, "0123456789abcdef", 16);
	return (ft_the_max(3, ptr->precis, ptr->field, len));
 }
