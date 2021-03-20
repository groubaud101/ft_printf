#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;
	size_t	index;

	len = n;
	if (*needle == 0)
		return ((char *)haystack);
	while (len && *haystack)
	{
		index = 0;
		while (*haystack == *needle && *needle && *haystack && len)
		{
			haystack++;
			needle++;
			index++;
			len--;
		}
		if (*needle == '\0')
			return ((char *)haystack - index);
		haystack = haystack - index + 1;
		needle-=index;
		len = len + index - 1;
	}
	return (NULL);
}