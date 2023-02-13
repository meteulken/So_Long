/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:46:09 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/05 19:34:39 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** set_enemy_position function will set the enemies coordinates in a 1D array
** its will be used to check while enemy is moving
*/

static void	set_enemy_position(t_game *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	game->enemies_coordinates = (int *)malloc(
			(game->map_height * game->map_width) * sizeof(int));
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'K')
			{
				game->enemies_coordinates[k++] = i;
				game->enemies_coordinates[k++] = j;
			}
			j++;
		}
		i++;
	}
	game->enemies_coordinates[k] = '\0';
}

/*
** set_player_position function will 
** set the player coordinates
** coordinates usable while map path correction 
** in the solution with find_path function
*/

static void	set_player_positions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

/*
** small_map function will check if the map is too small
** call ft_path_is_ok function after check map path horizontally in the loop
*/

static void	ft_validate_map_path(t_game *game)
{
	int	w;
	int	k;
	int	x;
	int	y;

	ft_small_map(game);
	x = 1;
	while (x < game->map_width)
	{
		y = 0;
		w = 0;
		k = 0;
		while (y < game->map_height && x != (game->map_width - 1))
		{
			if (game->map[y][x] == '1')
				w++;
			if (game->map[y][x] == 'K')
				k++;
			y++;
		}
		ft_path_is_ok(w, k, game->map_height);
		x++;
	}
	set_player_positions(game);
}

/*
** buffer[ft_strlen(buffer) - 1] != '\n' prevent 
** possible error for map layout
** because calculation the height of the map is based 
** on the number of '\n' easily you will see in 
** ft_check_map function for increment the height of the map
** and ft_check_map function will check if the map is 
** rectangular or needed calculation
*/

void	ft_validate_map(char **argv, t_program *program)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_file_is_open(fd);
	buffer = ft_get_map(fd);
	if (buffer[ft_strlen(buffer) - 1] != '\n')
		buffer = ft_join(buffer, '\n');
	ft_check_component(buffer, &program->window.game);
	program->window.game.map = ft_split(buffer, '\n');
	while (program->window.game.map[0][i] != '\0')
	{
		program->window.game.map_width++;
		i++;
	}
	ft_check_map(buffer, program);
	ft_validate_map_path(&program->window.game);
	set_enemy_position(&program->window.game);
	find_path(&program->window.game);
	free(buffer);
	close(fd);
}
