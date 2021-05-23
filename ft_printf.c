/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:58 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:49:36 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

// int integerValue = (int) va_arg( parametersInfos, int );

static t_printf	*ft_init_tprintf(t_printf *ptr)
{
	if (ptr == NULL)
	{
		ptr = (t_printf *)malloc(sizeof(t_printf));
		if (!ptr)
			return (NULL);
	}
	else
	{
		printf(YELLOW"\npat : |%s|\n", ptr->patern);
		if (ptr->patern)
	 		free(ptr->patern);
		//printf("TR result : |%s| |%p|\n", ptr->result, ptr->result);
	 	if (ptr->result)
	 		free(ptr->result);
		printf("COUCOU\n");
	}
	ptr->flag = "-0";
	ptr->conv = "cspdiuxX%";
	ptr->minus = -1;
	ptr->zero = -1;
	ptr->field = -1;
	ptr->precis = -1;
	ptr->explicit_precis = -1;
	ptr->num_conv = -1;
	ptr->patern = NULL;
	ptr->len_pat = -1;
	ptr->result = NULL;
	ptr->len_res = -1;
	return (ptr);
}

static const char	*ft_aff_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	write(1, (char *)format, i);
	return (format + i);
}

int	ft_printf(const char *format, ...)
{
	va_list 	params;
	t_printf	*ptr;
	int			ret;

	va_start(params, format);
	ret = ft_strlen(format);
	ptr = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ptr = ft_init_tprintf(ptr);
			printf("UN result : |%s| |%p|\n", ptr->result, ptr->result);
			if (ft_fill_tprintf(ptr, params, format) == -1)
				return (-1);
			printf("DE result : |%s| |%p|\n", ptr->result, ptr->result);
			// affichage du result + count du nb de catactere affiché
			if (ptr->conv[ptr->num_conv] != '%')
			{
				// ret = ft_aff_result(ptr);
				// ft_aff_tprintf(ptr);
				ft_putstr(ptr->result);

			}
			else
				ft_putchar('%');
			ret = ret - (ptr->len_pat + 1) + ft_strlen(ptr->result);

			format += ptr->len_pat;
		}
		format = ft_aff_format(format);
	}
	return (ret);
}
