/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:24:52 by mulken            #+#    #+#             */
/*   Updated: 2022/10/11 22:24:54 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*src2;
	size_t	i;

	i = 0;
	str = (char *)dest;
	src2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (dest);
}
/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char		*str1 = malloc(sizeof(char) * 5);
	char		*str2 = malloc(sizeof(char) * 5);
	const char	*src = "mete";
    ft_memcpy(str1,src,2);
    printf("%s\n", str1);
}*/
