#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (src < dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else if (src > dest)
		while (++index < n)
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
	return (dest);
}