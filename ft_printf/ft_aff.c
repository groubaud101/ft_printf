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
#include <unistd.h>

int	ft_aff_di(t_printf *ptr, int len, int neg)
{
	int		i;
	char	c;

	c = ' ';
	if (ptr->zero == 1)
		c = '0';
	if (neg && ptr->zero == 1)
		ft_putchar('-');		
	i = ft_the_max(2, ptr->precis, len);
	if (len == 0)
		i = 0;
	if (neg && ptr->zero != 1)
	{
		i++;
		ptr->precis++;
	}
	while (i++ < ptr->field)
		ft_putchar(c);		
	return (ft_the_max(3, ptr->precis, ptr->field, len));
}

int	ft_aff_diuxx(t_printf *ptr, int len)
{
	int		i;
	char	c;

	c = ' ';
	if (ptr->zero == 1)
		c = '0';
	i = ft_the_max(2, ptr->precis, len);
	if (len == 0)
		i = 0;

	while (i++ < ptr->field)
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
	i = ptr->precis;
	if (i < ptr->field)
	 	i = ptr->field;
	if (ptr->minus == 1)
	{
		if (ptr->zero != 1)
			ft_putstr("0x");
		ft_put_ulonglong_base(n, "0123456789abcdef");
	}
	while (i > 0 && i-- > len)
		ft_putchar(c);
	if (ptr->minus != 1)
	{
		if (ptr->zero != 1)
			ft_putstr("0x");
		ft_put_ulonglong_base(n, "0123456789abcdef");
	}
	return (ft_the_max(3, ptr->precis, ptr->field, len));
}

int		ft_aff_s(t_printf *ptr, const char *str)
{
	int		len;
	int		i;

	if ((ptr->field > -1 && ptr->precis == -1) || !(ptr->precis > -1))
		len = ft_strlen(str);
	else if (ptr->precis > -1)
		len = ft_the_min(2, ft_strlen(str), ptr->precis);
	i = ptr->field;
	if (ptr->minus == 1)
		write(1, str, len);
	while (i-- > len)
		ft_putchar(' ');
	if (ptr->minus != 1)
		write(1, str, len);
	return (ft_the_max(2, len, ptr->field));
}