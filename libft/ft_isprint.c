int	ft_isprint(int c)
{
	c = c % 256;
	if (c >= ' ' && c <= 126)
		return (1);
	return (0);
}