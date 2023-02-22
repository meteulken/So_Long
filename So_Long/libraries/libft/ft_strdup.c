/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:26:43 by mulken            #+#    #+#             */
/*   Updated: 2022/10/11 22:41:34 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (str[index])
	{
		ptr[index] = str[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
/*#include <stdio.h>
int	main(void)
{
	char str[] = "mete";
    printf("%s\n",ft_strdup(str));
    return (0);
}*/
