/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:57:40 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 18:09:58 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	test01(void)
{
	char	*ptr;
	char	*ptr2;

	ptr = NULL;
	ptr2 = malloc(10);
	printf("ori ret : %i\n", printf(RED"ori\nptr : |%p| ptr2 : |%p|\n"DEF,
				ptr, ptr2));
	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\nptr : |%p| ptr2 : |%p|\n"DEF,
				ptr, ptr2));

}

// plante pour double free
void	test02(void)
{
	printf("ori ret : %i\n", printf(RED"ori\n42 : -X : |%X| -x : |%x|\n"DEF,
				-42, -42));
	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\n42 : -X : |%X| -x : |%x|\n"DEF,
				-42, -42));
}

void	test03(void)
{
	printf("ori ret : %i\n", printf(RED"ori\n42 : X : |%X| X : |%X| X : |%X|\n"DEF,
				42, 42, 42));
	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\n42 : X : |%X| X : |%X| X : |%X|\n"DEF,
				42, 42, 42));
}


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

	// a faire ft_memory_to_a

	// printf("ori ret : %i\n\n", printf("ori\n-42 : u : |%u| x : |%x| X : |%X|\n",
	// 			-42, -42, -42));
	// printf("ft_ ret : %i\n", ft_printf("ft_\n-42 : u : |%u| x : |%x| X : |%X|\n",
	// 			-42, -42, -42));

	// test01();
	test02();
	// test03();

	return (0);
}
