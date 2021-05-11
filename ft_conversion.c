/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:45:56 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/11 12:45:56 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_conv_c(va_list params)
{
	char *str;
	char c;
	
	c = (unsigned char)va_arg(params, int);
	str = ft_calloc(sizeof(char), 2);
	if (!str)
		return (NULL);
	str[0] = c;
	return (str);
}

char	*ft_conv_s(va_list params)
{
	const char *str;
	
	str = (const char *)va_arg(params, const char *);
	return (ft_strdup(str));
}

char	*ft_conv_p(va_list params)
{
	int	nb;
	char			*str;
	char			*res;

	nb = (unsigned long long)va_arg(params, void *);
	str = ft_itoa_base(nb, "0123456789abcdef");
	if (!str)
		return (NULL);
	if (nb == 0)
		return (str);
	res = ft_strjoin("0x", str);
	free(str);
	return (res);
}

char	*ft_conv_d(va_list params)
{
	int	nb;

	nb = (int)va_arg(params, int);
	return (ft_itoa_base(nb, "0123456789"));
}

char	*ft_conv_i(va_list params)
{
	int	nb;

	nb = (int)va_arg(params, int);
	return (ft_itoa_base(nb, "0123456789"));	
}

char	*ft_conv_u(va_list params)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(params, unsigned int);
	return (ft_itoa_base(nb, "0123456789"));	
}

char	*ft_conv_x(va_list params)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(params, unsigned int);
	return (ft_itoa_base(nb, "0123456789abcdef"));	
}

char	*ft_conv_xup(va_list params)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(params, unsigned int);
	return (ft_itoa_base(nb, "0123456789ABCDEF"));	
}

char 	*ft_conversion(t_printf *ptr, va_list params)
{
	char	*(*tab[9])(va_list params);

	tab[0] = &ft_conv_c;
	tab[1] = &ft_conv_s;
	tab[2] = &ft_conv_p;
	tab[3] = &ft_conv_d;
	tab[4] = &ft_conv_i;
	tab[5] = &ft_conv_u;
	tab[6] = &ft_conv_x;
	tab[7] = &ft_conv_xup;

	return (tab[ptr->num_conv](params));
}