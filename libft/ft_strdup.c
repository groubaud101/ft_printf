#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		index;

	str = (char *)ft_calloc(sizeof(*str), ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = s[index];
		index++;
	}
	return (str);
}