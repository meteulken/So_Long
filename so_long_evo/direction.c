/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:13:30 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/01 00:29:41 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** ft_map_availability checks if the player can move to 
** the next position if the next position is a collectible, 
** it will be removed from the map
** if the next position is the exit, the game will be 
** closed when collectibles = 0
** if the next position is an enemy, the game will be closed
** returns 1 if conditions are met, 0 otherwise
*/

int	ft_map_availability(char **map, int y, int x, t_program *program)
{
	if (program->window.game.collectibles == 0 && map[y][x] == 'E')
	{
		ft_putstr_fd("You won!\n", 1);
		ft_close(program);
	}
	if (map[y][x] == 'C')
		program->window.game.collectibles--;
	if (map[y][x] == 'K')
	{
		ft_putstr_fd("You lost!\n", 1);
		ft_close(program);
	}
	return (map[y][x] != '1' && map[y][x] != 'E');
}

int	ft_redirect_player(char *curr, char *redirected)
{
	*curr = '0';
	*redirected = 'P';
	return (1);
}
