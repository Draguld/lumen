#include "ft_itos.hpp"

int				ft_intsign(int n)
{
	if (n >= 0)
		return (0);
	return (1);		
}

int				ft_intlen(int n)
{
	int		result = 0;
	if (n < 0)
	 n = n * -1;
	while (n >= 10)
	{
		result++;
		n = n / 10;		
	}
	return (result++);
}

std::string		ft_itos(int n)
{

	std::string		result;
	int				nlen = ft_intlen(n);
	int				nsign = ft_intsign(n);
	int				i = nlen;
	char			*buffer;

	if (nsign == 1)
		n = n * -1;
	buffer = (char *)malloc(sizeof(*buffer) * nlen + nsign + 1);
	if (buffer == NULL)
		return (NULL);
	buffer = buffer + nlen + nsign + 1;
	*buffer = '\0';
	while (i >= 0)
	{
		buffer--;
		*buffer = n % 10 + '0';
		n = n / 10;
		i--;		
	}
	if (nsign == 1)
	{
		buffer--;
		*buffer = '-';		
	}
	result = buffer;
	free(buffer);
	return (result);
}
