#include <stdlib.h>
#include "libft.h"

static int		ft_special_strlen(char const *s, int start, char end)
{
	int	index;

	index = 0;
	while (s[index + start] && s[index + start] != end)
		index++;
	return (index);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	ct;

	ct = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ct++;
		while (*s && *s != c)
			s++;
	}
	return (ct);
}

static char		**ft_free_tab(char **tab, int len)
{
	while (len)
		free(tab[--len]);
	free(tab);
	return (NULL);
}

static char		**ft_split2(char const *s, char c, char **tab)
{
	int		index;
	int		len;

	index = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = ft_special_strlen(s, 0, c);
			tab[index] = (char *)ft_calloc(sizeof(**tab), len + 1);
			if (!(tab[index]))
				return (ft_free_tab(tab, index));
			ft_strlcpy(tab[index], s, len + 1);
			s = s + len;
			index++;
		}
	}
	tab[index] = NULL;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s && *s == c)
		s++;
	tab = ft_split2(s, c, tab);
	if (!tab)
		return (NULL);
	return (tab);
}
