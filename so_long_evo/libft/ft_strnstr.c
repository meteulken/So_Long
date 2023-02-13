/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:28:36 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/25 23:24:38 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	pos;

	if (!needle)
		return ((char *)haystack);
	pos = ft_strlen((char *)needle);
	while (*haystack++ != '\0' && n-- >= pos)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, pos) == 0)
			return ((char *)haystack);
	}
	return (NULL);
}
