

#include "libft.h"

static int	count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i++])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char	*strndup(const char *s, size_t n)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL || !s || !str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	d;
	char			**table;

	a = 0;
	d = 0;
	table = malloc((count(s, c) + 1) * sizeof * table);
	if (table == NULL || !s)
		return (NULL);
	while (s[a])
	{
		while (s[a] == c)
			a++;
		b = a;
		while (s[a] && s[a] != c)
			a++;
		if (b < a)
			table[d++] = strndup(s + b, a - b);
	}
	table[d] = NULL;
	return (table);
}
