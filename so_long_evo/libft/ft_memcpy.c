/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:52:30 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/13 14:30:39 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstt;
	const unsigned char	*srct;
	size_t				i;

	if (!dst && !src)
		return (0);
	dstt = (unsigned char *)dst;
	srct = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dstt[i] = srct[i];
		i++;
	}
	dst = dstt;
	return (dst);
}
