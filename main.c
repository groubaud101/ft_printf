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

// void	test01(void)
// {
// 	char	*ptr;
// 	char	*ptr2;

// 	ptr = NULL;
// 	ptr2 = malloc(10);
// 	printf("ori ret : %i\n", printf(RED"ori\nptr : |%p| ptr2 : |%p|\n"DEF,
// 				ptr, ptr2));
// 	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\nptr : |%p| ptr2 : |%p|\n"DEF,
// 				ptr, ptr2));

// }

// // plante pour double free
// void	test02(void)
// {
// 	printf("ori ret : %i\n", printf(RED"ori\n42 : -X : |%X| -x : |%x|\n"DEF,
// 				-42, -42));
// 	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\n42 : -X : |%X| -x : |%x|\n"DEF,
// 				-42, -42));
// }

void	test03(void)
{
	printf("ori ret : %i\n", printf(RED"ori\n42 : %%X : |%X| %%X : |%X| %%X : |%X|\n"DEF,
				42, 42, 42));
	printf("ft_ ret : %i\n\n", ft_printf(CYAN"ft_\n42 : %%X : |%X| %%X : |%X| %%X : |%X|\n"DEF,
				42, 42, 42));
}

// void	test04(void)
// {
// 	int	ret;

// 	ret = printf("01 |%05i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n02 |%.5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n03 |%-5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n04 |%-.5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n05 |%.-5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n06 |%.5s|\n", "sa");
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n07 |%.5s|\n", "salut ca va ?");
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n08 |%-0.5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n09 |%-03.5i|\n", 10);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n10 |%-03i|\n", 10);
// 	printf("ret : %i\n", ret);
// }

// void	test_05(void)
// {
// 	char	*str;
// 	int		ret;

// 	str = "coucou";
// 	ret = printf("01 %%10s : |%10s|\n", str);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n02 %%.10s : |%.10s|\n", str);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n03 %%2s : |%2s|\n", str);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n04 %%.2s : |%.2s|\n", str);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n05 %%3.2s |%3.2s|\n", str);
// 	printf("ret : %i\n", ret);

// }

// void	test_06_c()
// {
// 	char	c;

// 	c = '1';

// 	ret = printf("\n01 %%3c : |%3c|\n", c);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n06 %%3c : |%3c|\n", 0);
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n02 %%.10c : |%.10c|\n", c); //erreur
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n03 %%0c : |%0c|\n", c); // erreur
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n04 %%.2c : |%.2c|\n", c); //erreur
// 	printf("ret : %i\n", ret);

// 	ret = printf("\n05 %%3.2c |%3.2c|\n", c); //erreur
// 	printf("ret : %i\n", ret);

// }

int		main()
{
	int	ret;
	int	ret2;
	char	*str;

	// test01();
	// test02();
	test03();
	// test_04();
	// test_05_s();
	//test_06_c();

	return (0);
}
