/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 01:21:41 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/01 00:03:25 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_map_char(char c)
{
	if (c != '1' && c != 'P' && c != 'C' && c != 'E'
		&& c != '0' && c != 'K' && c != '\n')
	{
		ft_putstr_fd("Error!\nInvalid character in the map.\n", 1);
		ft_putstr_fd("Valid characters are: 1, P, C, E, 0, K, \\n\n", 1);
		ft_putstr_fd("Invalid character is: ", 1);
		ft_putchar_fd(c, 1);
		ft_putstr_fd("\n", 1);
		exit (0);
	}
}

void	ft_limits_error(void)
{
	ft_putstr_fd("Error!\nNot enough trees in the screen limits.\n", 1);
	ft_putstr_fd("Please, plant 1 where they are supposed to be.\n", 1);
	exit (1);
}

void	ft_file_is_open(int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error!\nThe map could not be read.\n", 1);
		exit (1);
	}
}

void	ft_small_map(t_game *game)
{
	if (game->map_height < 3 || game->map_width < 3)
	{
		ft_putstr_fd("Error!\nThe map is too small.\n", 1);
		exit (0);
	}
}

void	ft_path_is_ok(int W, int K, int y)
{
	if (((W > 0 || K > 0) && (W == y || K == y)) || (W + K) == y)
	{
		ft_putstr_fd("Error!\nPath sequence is illogical in the map.\n", 1);
		exit (0);
	}
}
