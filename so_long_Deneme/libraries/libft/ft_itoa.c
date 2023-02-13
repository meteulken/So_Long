
#include "libft.h"

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*itoa;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	itoa = malloc(sizeof(char) * len + 1);
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	while (nbr > 0)
	{
		itoa[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	if (n == 0)
		itoa[0] = '0';
	return (itoa);
}
