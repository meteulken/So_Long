/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:21:06 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/06 01:57:03 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struct(t_program *program, int is_bonus)
{
	program->window.game.map_width = 0;
	program->window.game.map_height = 0;
	program->window.game.collectibles = 0;
	program->window.game.exit = 0;
	program->window.game.player = 0;
	program->window.game.player_x = 0;
	program->window.game.player_y = 0;
	program->window.game.moves_total = 0;
	program->window.game.map_directions.east = 0;
	program->window.game.map_directions.west = 0;
	program->window.game.map_directions.north = 0;
	program->window.game.map_directions.south = 0;
	program->window.game.map_directions.p_and_c_total = 0;
	program->is_bonus = is_bonus;
}

void	define_frames(t_program *program)
{
	t_game	*g;

	g = &program->window.game;
	g->frames.p = ft_img(program->mlx, "./textures/player.xpm");
	g->frames.c = ft_img(program->mlx, "./textures/collectible.xpm");
	g->frames.e = ft_img(program->mlx, "./textures/exit.xpm");
	g->frames.w = ft_img(program->mlx, "./textures/wall.xpm");
	g->frames.f = ft_img(program->mlx, "./textures/floor.xpm");
	if (program->is_bonus)
		g->frames.k = ft_img(program->mlx, "./textures/enemy.xpm");
}

void	ft_reset_program(t_program program)
{
	free(program.mlx);
	free(program.window.reference);
	free(program.window.game.frames.p.pixels);
	free(program.window.game.frames.c.pixels);
	free(program.window.game.frames.e.pixels);
	free(program.window.game.frames.w.pixels);
	free(program.window.game.frames.f.pixels);
	free(program.window.game.frames.k.pixels);
	free_map_c(program.window.game.map, program.window.game.map_height);
	ft_close(&program);
}
