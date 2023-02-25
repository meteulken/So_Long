/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:59:53 by mulken            #+#    #+#             */
/*   Updated: 2023/02/22 14:12:48 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "images/player_back.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "images/player_front.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "images/player_right.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "images/player_left.xpm", &game->img_w, &game->img_h);
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	player_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		map_draw(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
