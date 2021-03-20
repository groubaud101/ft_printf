#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*tmp;
	const char	*tmp2;

	index = 0;
	tmp = (char *)dest;
	tmp2 = (const char *)src;
	while (index < n)
	{
		tmp[index] = tmp2[index];
		index++;
	}
	dest = (void *)tmp;
	return (dest);
}