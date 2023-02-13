/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:57:00 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/26 00:43:27 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_int_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (i);
}

static	char	*to_string(int n, int len, int num, char *str)
{
	while (len >= 0)
	{
		num = n % 10;
		str[len--] = num + 48;
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		num;
	int		sign;

	len = get_int_length(n);
	num = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483649"));
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	str[len--] = '\0';
	to_string(n, len, num, str);
	if (sign == -1 && str[0] == '0')
		str[0] = '-';
	return (str);
}
