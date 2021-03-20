#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;
	size_t			slen;
	size_t			dlen;

	slen = ft_strlen(s);
	if (start > slen)
		return ((char *)ft_calloc(sizeof(*str), 1));
	if (slen > len)
		dlen = len;
	else
		dlen = slen - start;
	str = (char *)ft_calloc(sizeof(*str), (dlen + 1));
	if (!str)
		return (NULL);
	index = start;
	while (index - start < dlen && s[index])
	{
		str[index - start] = s[index];
		index++;
	}
	return (str);
}