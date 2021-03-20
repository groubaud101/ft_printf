#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (index);
	while (s[index])
		index++;
	return (index);
}