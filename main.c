/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:57:40 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/11 10:57:40 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	// printf("ori : [%%--4i] |%--4i|, |%i|\n", 42, 19);
	// printf("ori : [%%-4%%] |%-4%|, |%i|\n\n", 42, 19);
	// printf("ori : [1234]; |%.*i|", 10, 42);
	// printf("ori : *; |%.*i|", 10, 42);

	// ft_printf("1ft_ : [%%-4%%] |%-4%|\n\n");
	// ft_printf("2ft_ : [%%--0000-25.i] : |%--0000-25.i|\n[%%01d] : |%01d|\n[%%0.1d] : |%0.1d|", 19, 42, 101);
	// ft_printf("3ft_ : [1234]; %1234");
	// ft_printf("I   /-05.3i : |%-05.3i|\n", 42);
	// ft_printf("II  /-0*(4).3i : |%-0*.3i|\n", 4, 42);
	// ft_printf("III /-05.*(5)i : |%-05.*i|\n", 5, 42);
	// ft_printf("IV  /-0*(2).*(3)i : |%-0*.*i|\n", 2, 3, 42);
	// printf("ori ret : %i\n\n", printf("ori\n42 : |%i| coucou : |%s| c : |%c|\n",
	// 			42, "coucou", 'c'));
	// printf("ft_ ret : %i\n", ft_printf("ft_\n42 : |%i| coucou : |%s| c : |%c|\n",
	// 			42, "coucou", 'c'));
	printf("ori ret : %i\n\n", printf("ori\n42 : |%i|\n",
				42, "coucou", 'c'));
	printf("ft_ ret : %i\n", ft_printf("ft_\n42 : |%i|\n",
				42, "coucou", 'c'));

	return (0);
}