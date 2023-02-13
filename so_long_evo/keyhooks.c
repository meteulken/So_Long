/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:34:01 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/04 12:51:16 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_movements(t_game *game)
{
	ft_putstr_fd("Total moves -> ", 1);
	ft_putnbr_fd(game->moves_total, 1);
	ft_putstr_fd("\n", 1);
}

/*
** display the total movements on the screen
** the score position is calculated by 
** the map width and the animation frames divided by 4
*/

void	ft_put_display(t_program *program)
{
	char	*str;
	int		score_position;

	score_position = program->window.game.map_width * ANIMATION_FRAMES;
	str = ft_itoa(program->window.game.moves_total);
	mlx_string_put(program->mlx, program->window.reference,
		score_position - (score_position / 4), 70, 0x800000,
		"Movements: ");
	mlx_string_put(program->mlx, program->window.reference,
		score_position - (score_position / 4) + 70, 70, 0x800000,
		str);
	free(str);
}

static void	ft_is_move(t_program *program, int is_move, int is_bonus)
{
	if (is_move)
	{
		program->window.game.moves_total++;
		if (is_bonus)
			ft_put_display(program);
		else
			ft_put_movements(&program->window.game);
	}
}

int	ft_movements_keyhooks(int key, t_program *program, int is_bonus)
{
	int		y;
	int		x;
	char	**curr_map;
	int		is_move;

	is_move = 0;
	y = program->window.game.player_y;
	x = program->window.game.player_x;
	curr_map = program->window.game.map;
	if ((key == RIGHT_KEY || key == D_KEY)
		&& ft_map_availability(curr_map, y, x + 1, program))
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y][x + 1]);
	else if ((key == LEFT_KEY || key == A_KEY)
		&& ft_map_availability(curr_map, y, x - 1, program))
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y][x - 1]);
	else if ((key == DOWN_KEY || key == S_KEY)
		&& ft_map_availability(curr_map, y + 1, x, program))
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y + 1][x]);
	else if ((key == UP_KEY || key == W_KEY)
		&& ft_map_availability(curr_map, y - 1, x, program))
		is_move = ft_redirect_player(&curr_map[y][x], &curr_map[y - 1][x]);
	ft_is_move(program, is_move, is_bonus);
	return (0);
}
