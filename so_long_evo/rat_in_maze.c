/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rat_in_maze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:55:10 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/09 20:02:28 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_frame(char frame, int is_path_used)
{
	return (frame != '1' && frame != 'K' && !is_path_used);
}

static int	seek_map(t_game *game, int y, int x)
{
	game->map_directions.seeker.y = y;
	game->map_directions.seeker.x = x;
	if (game->map[y][x] == 'P' || game->map[y][x] == 'C')
		game->map_directions.p_and_c_total++;
	if (is_valid_frame(game->map[y][x + 1], game->solution[y][x + 1]))
	{
		game->solution[y][x + 1] = game->solution[y][x] + 1;
		seek_map(game, y, x + 1);
	}
	if (is_valid_frame(game->map[y + 1][x], game->solution[y + 1][x]))
	{
		game->solution[y + 1][x] = game->solution[y][x] + 1;
		seek_map(game, y + 1, x);
	}
	if (is_valid_frame(game->map[y][x - 1], game->solution[y][x - 1]))
	{
		game->solution[y][x - 1] = game->solution[y][x] + 1;
		seek_map(game, y, x - 1);
	}
	if (is_valid_frame(game->map[y - 1][x], game->solution[y - 1][x]))
	{
		game->solution[y - 1][x] = game->solution[y][x] + 1;
		seek_map(game, y - 1, x);
	}
	return (1);
}

void	find_path(t_game *game)
{
	int	map_is_seeked;

	set_solution_map_to_int(game);
	game->solution[game->exit_y][game->exit_x] = 1;
	game->map_directions.seeker.x = game->exit_x;
	game->map_directions.seeker.y = game->exit_y;
	map_is_seeked = seek_map(game, game->exit_y, game->exit_x);
	if (!map_is_seeked)
		err_msg("Error\nFatal error, check the rat_in_maze.c file!\n");
	if (game->map_directions.p_and_c_total != game->collectibles + 1)
		err_msg("Error\nMap is not reachable!\n");
	ft_putstr_fd("Map is seeked\n", 1);
	ft_putstr_fd("Seeker last position: ", 1);
	ft_putnbr_fd(game->map_directions.seeker.x, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(game->map_directions.seeker.y, 1);
	ft_putstr_fd("\n", 1);
	free_map(game->solution, game->map_height);
}
