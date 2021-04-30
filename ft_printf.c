/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:58 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/29 13:03:59 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

// int integerValue = (int) va_arg( parametersInfos, int );


int	ft_printf(const char *format, ...)
{
	va_list params;
	size_t	index;

	va_start(params, format);
	// verif de la chaine 1
	while (*format)
	{
		index = 0;
		if (*format == '%')
		{
			// verif du patern
			// remplissage de la structure
			// avec la selection du segment (patern)
			// et le nombre de caractere (len_patern)
			// calcul de la taille finale (len_result)
			// avec création de la chaine (result)

			// ifs pour le type et redirection (what_is_your_kind)

			// remplissage du result

			// affichage du result

			format++;
			if (*format == 'i')
			{
				int integerValue = (int)va_arg( params, int);
				ft_putnbr(integerValue);
			}
			else if (*format == 's')
			{
				char *str = (char *)va_arg(params, char *);
				ft_putstr(str);
			}
			else if (*format == 'c')
			{
				char c = (unsigned char)va_arg(params, int);
				ft_putchar(c);
			}
			format++;
		}
		ft_putchar(*format);
		format++;
		index++;
	}
	return (0);
}