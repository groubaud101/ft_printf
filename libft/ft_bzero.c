#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*tmp;

	index = 0;
	tmp = (char *)s;
	while (index < n)
	{
		tmp[index] = '\0';
		index++;
	}
	s = (void *)tmp;
}