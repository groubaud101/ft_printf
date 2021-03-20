#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	index;

	index = 0;
	result = (char *)ft_calloc(sizeof(*result), ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	return(result);
}