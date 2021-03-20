#include <string.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memcmp((const void *)s1, (const void *)s2, n));
}