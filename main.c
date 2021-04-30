#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	printf("%i : |%5.5i|, |%.0d|\n", 1234, 1234, 0);
	ft_printf("Bonjour, j'ai %i ans, je m'appelle %s et la premiere lettre de mon nom est %c\n",
				29, "Guillaume", 'R');
}