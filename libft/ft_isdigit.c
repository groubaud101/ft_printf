int	ft_isdigit(int c)
{
	c = c % 256;
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}