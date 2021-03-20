#include "libft.h"

static char	*ft_rec_itoa_base(int n, char *nbr, int i, char *base)
{
	if (n > 9 || n < -9)
		nbr = ft_rec_itoa_base(n / ft_strlen(base), nbr, i - 1, base);
	nbr[i] = base[ft_abs(n % ft_strlen(base))];
	return (nbr);
}

int		ft_nbrlen_base(int n, int b)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / b;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int n, char *base)
{
	int		len_nbr;
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	len_nbr = ft_nbrlen_base(n, ft_strlen(base));
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_itoa_base(n, nbr, len_nbr - 1, base);
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}