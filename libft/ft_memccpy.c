#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	index;
	char	*tmp;
	char	*tmp2;

	index = 0;
	if (n == 0)
		return (NULL);
	tmp = (char *)dest;
	tmp2 = (char *)src;
	while (index < n)
	{
		tmp[index] = tmp2[index];
		if (tmp2[index] == c)
		{
			dest = (void *)tmp;
			return (dest + index + 1);
		}
		index++;
	}
	return (NULL);
}