int	ft_isalpha(int c)
{
	c = c % 256;
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}