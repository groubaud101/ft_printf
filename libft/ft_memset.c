#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;
	char	*tmp;

	index = 0;
	tmp = (char *)s;
	while (index < n)
	{
		tmp[index] = c;
		index++;
	}
	s = (void *)tmp;
	return (s);
}