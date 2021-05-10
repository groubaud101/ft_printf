#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	printf("ori : [%%--4i] |%--4i|, |%i|\n", 42, 19);
	printf("ori : [%%-4%%] |%-4%|, |%i|\n\n", 42, 19);
	// ft_printf("1ft_ : [%%-4%%] |%-4%|\n\n");
	// ft_printf("2ft_ : [%%--0000-25.i] : |%--0000-25.i|\n[%%01d] : |%01d|\n[%%0.1d] : |%0.1d|", 19, 42, 101);
	ft_printf("3ft_ : [1234]; %1234");
}