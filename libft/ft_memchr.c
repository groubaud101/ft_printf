#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*tmp;

	index = 0;
	c = c % 256;
	tmp = (char *)s;
	while (index < n)
	{
		if (tmp[index] == c)
			return ((void *)tmp + index);
		index++;
	}
	return (NULL);
}