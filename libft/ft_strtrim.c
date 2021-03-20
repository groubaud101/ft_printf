#include <string.h>
#include "libft.h"

static int	ft_isinstr(char c, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}

static int	ft_strlentrim(char const *s1, char const *set)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (ft_isinstr(s1[index], set) == 1)
		index++;
	if (s1[index] == '\0')
		return (0);
	while (s1[index])
	{
		index++;
		len++;
	}
	index--;
	while (index >= 0 && ft_isinstr(s1[index], set) == 1)
	{
		index--;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		jndex;
	char	*trim;
	int		len;

	len = ft_strlentrim(s1, set);
	trim = (char *)ft_calloc(sizeof(*trim), len + 1);
	if (!trim)
		return (NULL);
	if (len == 0)
		return (trim);
	index = 0;
	jndex = 0;
	while (ft_isinstr(s1[index], set) == 1)
		index++;
	while (jndex < len)
	{
		trim[jndex] = s1[index];
		jndex++;
		index++;
	}
	return (trim);
}