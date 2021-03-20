#include "libft.h"

void	ft_puttab_fd(char **tab, char *sep, int fd)
{
	int		index;

	index = 0;
	if (!tab || !tab[index])
		return ;
	while (tab[index])
	{
		ft_putstr_fd(tab[index], fd);
		index++;
		if (tab[index])
			ft_putstr_fd(sep, fd);
	}
	ft_putchar_fd('\n', fd);
}