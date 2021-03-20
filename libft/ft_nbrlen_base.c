int	ft_nbrlen_base(int n, int len_base)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}