int	ft_isascii(int c)
{
	c = c % 256;
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}