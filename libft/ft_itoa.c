#include "libft.h"

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, "0123456789"));
}