/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:57:40 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/13 17:29:01 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	test_01_di(void)
{
	int		ret;
	int		ret2;
	int		i = 0;

#if 0
	ret = printf("ori |%i|\n", 42);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ |%i|\n", 42);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-011.6i %%-011.0i : |%-0*.6i| |%-0*.0i|\n",
					i, 11, 1021, 11, -1011);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-011.6i %%-011.0i : |%-0*.6i| |%-0*.0i|\n",
					i, 11, 1021, 11, -1011);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-0-11.10i %%-011.0i : |%0*.0i| |%0*.10i|\n",
					i, -11, INT_MAX, 11, INT_MIN);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-0-11.10i %%-011.0i : |%0*.0i| |%0*.10i|\n",
					i, -11, INT_MAX, 11, INT_MIN);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-0*.10i %%-0*.0i : |%0*.0i| |%0*.10i|\n",
	ret2 = ft_printf("ft_ %02i %%-0*.10i %%-0*.0i : |%0*.0i| |%0*.10i|\n",
					i, -21, LONG_MAX, 21, LONG_MIN);
	printf("ret : %i\n\n", ret2);
	i++;
#endif
	ret = printf("ori %%-0*(10).8i |%-0*.8i|\n",
					10, CHAR_MIN);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%-0*(10).8i |%-0*.8i|\n",
					10, CHAR_MIN);
	printf("ret : %i\n\n", ret2);
	i++;

	// ret = printf("ori %02i %%0*i : |%0*i|\n",
	// 				i, 10, -1011);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%0*i : |%0*i|\n",
	// 				i, 10, -1011);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%0*(21).*(10)i: |%0*.*i|*0\n",
	// 				i, 21, 10, -101);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%0*(21).*(10)i: |%0*.*i|*0\n",
	// 				i, 21, 10, -101);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%-3.2i %%4.6i : |%-3.2i| |%4.6i|\n", i, 1, -1);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%-3.2i %%4.6i : |%-3.2i| |%4.6i|\n", i, 1, -1);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%-3.2i %%6.4i : |%-3.2i| |%6.4i|\n", i, 1, -1);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%-3.2i %%6.4i : |%-3.2i| |%6.4i|\n", i, 1, -1);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%.d : |%.d|\n", i, 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%.d : |%.d|\n", i, 0);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%.0d : |%.0d|\n", i, 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%.0d : |%.0d|\n", i, 0);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%4.0d : |%4.0d|\n", i, 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%4.0d : |%4.0d|\n", i, 0);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%4.2d : |%4.2d|\n", i, 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%4.2d : |%4.2d|\n", i, 0);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%3.2d : |%3.2d|\n", i, 1);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%3.2d : |%3.2d|\n", i, 1);
	// printf("ret : %i\n\n", ret2);
	// i++;

	// ret = printf("ori %02i %%.d : |%.d|\n", i, 1);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %02i %%.d : |%.d|\n", i, 1);
	// printf("ret : %i\n\n", ret2);
	// i++;


}

void	test02(void)
{
	printf("ori ret : %i\n", printf("ori\n42 : -X : |%X| -x : |%x|\n",
				-42, -42));
	printf("ft_ ret : %i\n\n", ft_printf("ft_\n42 : -X : |%X| -x : |%x|\n",
				-42, -42));
}

void	test03(void)
{
	printf("ori ret : %i\n\n", printf("ori\n42 : %%X : |%X| %%X : |%X| %%X : |%X|\n",
				42, 42, 42));
	printf("ft_ ret : %i\n", ft_printf("ft_\n42 : %%X : |%X| %%X : |%X| %%X : |%X|\n",
				42, 42, 42));
}

void	test_04(void)
{
	int	ret;
	int ret2;

	// ret = printf(" 01 |%05i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%05i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 02 |%.5i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%.5i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 03 |%-5i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%-5i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 04 |%-.5i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%-.5i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	ret = printf(" 05 |%.-5i|\n", 10);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ |%.-5i|\n", 10);
	printf("ret : %i\n\n", ret2);

	// ret = printf(" 06 |%.5s|\n", "sa");
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%.5s|\n", "sa");
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 07 |%.5s|\n", "salut ca va ?");
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%.5s|\n", "salut ca va ?");
	// printf("ft_ : %i\n\n", ret2);

	// ret = printf(" 08 |%-0.5i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%-0.5i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 09 |%-03.5i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%-03.5i|\n", 10);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 10 |%-03i|\n", 10);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ |%-03i|\n", 10);
	// printf("ret : %i\n\n", ret2);
}

void	test_05_s(void)
{
	char	*str;
	int		ret;
	int		ret2;
	int		i = 0;
	str = "coucou";

	ret = printf("ori %02i %%-3.s : _%-3.s_\n", i, NULL);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-3.s : _%-3.s_\n", i, NULL);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-9.1s : _%-9.1s_\n", i, NULL);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-9.1s : _%-9.1s_\n", i, NULL);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%s : _%s_\n", i, NULL);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ori %02i %%s : _%s_\n", i, NULL);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-4s %%4s : |%-6s %4s|\n", i, "123", "4567");
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-4s %%4s : |%-6s %4s|\n", i, "123", "4567");
	printf("ret : %i\n\n", ret2);
	i++;
#if 0
	ret = printf(" 01 %%10s : |%10s|\n", str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%10s : |%10s|\n", str);
	printf("ret : %i\n\n", ret2);

	ret = printf(" 02 %%.10s : |%.10s|\n", str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%.10s : |%.10s|\n", str);
	printf("ret : %i\n\n", ret2);

	ret = printf(" 03 %%2s : |%2s|\n", str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%2s : |%2s|\n", str);
	printf("ret : %i\n\n", ret2);

	ret = printf(" 04 %%.2s : |%.2s|\n", str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%.2s : |%.2s|\n", str);
	printf("ret : %i\n\n", ret2);

	ret = printf(" 05 %%3.2s |%3.2s|\n", str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%3.2s |%3.2s|\n", str);
	printf("ret : %i\n\n", ret2);
#endif
}

void	test_06_c()
{
	char	c;
	int		ret;
	int		ret2;

	c = '1';

	ret = printf(" 01 %%c : |%c|\n", 0);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%c : |%c|\n", 0);
	printf("ret : %i\n\n", ret2);

	ret = printf(" 01  -%%-2c* -%%2c* : | -%-2c* -%2c* |\n", 0, 0);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_  -%%-2c* -%%2c* : | -%-2c* -%2c* |\n", 0, 0);
	printf("ret : %i\n\n", ret2);

	// ret = printf(" 01  -%%*c* -%%-*c* : | -%*c* -%-*c* |\n", -3, 0, 2, 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_  -%%*c* -%%-*c* : | -%*c* -%-*c* |\n", -3, 0, 2, 0);
	// printf("ret : %i\n\n", ret2);

	ret = printf(" 01 %%-c%%-c%%c* : |%-c%-c%c*|\n", 1, '0', 0);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %%-c%%-c%%c* : |%-c%-c%c*|\n", 1, '0', 0);
	printf("ret : %i\n\n", ret2);

	// ret = printf(" 01 %%3c : |%3c|\n", c);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%3c : |%3c|\n", c);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 06 %%3c : |%3c|\n", 0);
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%3c : |%3c|\n", 0);
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 02 %%.10c : |%.10c|\n", c); //erreur
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%.10c : |%.10c|\n", c); //erreur
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 03 %%0c : |%0c|\n", c); // erreur
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%0c : |%0c|\n", c); // erreur
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 04 %%.2c : |%.2c|\n", c); //erreur
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%.2c : |%.2c|\n", c); //erreur
	// printf("ret : %i\n\n", ret2);

	// ret = printf(" 05 %%3.2c |%3.2c|\n", c); //erreur
	// printf("ret : %i\n", ret);
	// ret2 = ft_printf("ft_ %%3.2c |%3.2c|\n", c); //erreur
	// printf("ret : %i\n\n", ret2);

}

void	test_07_p()
{
	int		i;
	int		ret;
	int		ret2;
	char	*str;

	ret = printf("ori %%2.9p : |%2.9p|\n", 1234);
	ret2 = ft_printf("ft_ %%2.9p : |%2.9p|\n", 1234);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%5.p : |%5.p|\n", NULL);
	ret2 = ft_printf("ft_ %%5.p : |%5.p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

#if 0
	ret = printf("ori %%5p : |%5p|\n", NULL);
	ret2 = ft_printf("ft_ %%5p : |%5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%05p : |%05p|\n", NULL);
	ret2 = ft_printf("ft_ %%05p : |%05p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00--5p : |%00--5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00--5p : |%00--5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00--.5p : |%00--.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00--.5p : |%00--.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00--3.5p : |%00--3.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00--3.5p : |%00--3.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00--5.3p : |%00--5.3p|\n", NULL);
	ret2 = ft_printf("ft_ %%00--5.3p : |%00--5.3p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%0-.5p : |%0-.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%0-.5p : |%0-.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%0--.5p : |%0--.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%0--.5p : |%0--.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00-.5p : |%00-.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00-.5p : |%00-.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%00-5p : |%00-5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00-5p : |%00-5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);
	
	ret = printf("ori %%00.5p : |%00.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%00.5p : |%00.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%--.5p : |%--.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%--.5p : |%--.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%--5p : |%--5p|\n", NULL);
	ret2 = ft_printf("ft_ %%--5p : |%--5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%--.5p : |%--.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%--.5p : |%--.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);

	ret = printf("ori %%--10.5p : |%--10.5p|\n", NULL);
	ret2 = ft_printf("ft_ %%--10.5p : |%--10.5p|\n", NULL);
	printf("ori : %i, ft_ : %i\n\n", ret, ret2);
#endif
#if 1
	i = 1;
	str = malloc(10);

	ret = printf("ori %02i %%10p %%-10p : |%10p %-10p|\n", i, 0, 0);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%10p %%-10p : |%10p %-10p|\n", i, 0, 0);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%p : |%p|\n", i, str);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%p : |%p|\n", i, str);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%12p : |%12p|\n", i, -1);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%12p : |%12p|\n", i, -1);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%-12p : |%-12p|\n", i, -1);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%-12p : |%-12p|\n", i, -1);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%014p : |%014p|\n", i, -1);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%014p : |%014p|\n", i, -1);
	printf("ret : %i\n\n", ret2);
	i++;

	ret = printf("ori %02i %%10p : |%10p|\n", i, 16);
	printf("ret : %i\n", ret);
	ret2 = ft_printf("ft_ %02i %%10p : |%10p|\n", i, 16);
	printf("ret : %i\n\n", ret2);
#endif
}

int		main()
{
	int	ret;
	int	ret2;
	char	*str;

	// test_01_di();
	// test02();
	// test03();
	// test_04();
	//test_05_s();
	// test_06_c(); // à test sur guacamole
	test_07_p(); // à test sur guacamole, que renvoyer quand p est 0
	return (0);
}
