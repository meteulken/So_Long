/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:19:11 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/09 20:03:07 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** while enemy is moving, check_player_for_enemy function will check 
** if the the player position is the same as the enemy position
*/

static void	check_player_for_enemy(t_program *program, int enemy_x, int enemy_y)
{
	int	x;
	int	y;

	y = program->window.game.player_y;
	x = program->window.game.player_x;
	if (enemy_x == x && enemy_y == y)
	{
		ft_putstr_fd("You lost!\n", 1);
		ft_close(program);
		exit(0);
	}
}

/*
** swap_enemy function will swap the enemy position
** when triggered, the enemy will move to the right
** when triggered again, the enemy will move to the left
** and while moving to the left, it will check 
** if the player is in the same position
*/

static void	swap_enemy(t_program *program, int is_enemy)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	while (i < program->window.game.enemies_coordinates[i])
	{
		y = program->window.game.enemies_coordinates[i];
		x = program->window.game.enemies_coordinates[i + 1];
		if (is_enemy)
		{
			program->window.game.map[y][x] = 'K';
			check_player_for_enemy(program, x, y);
		}
		else
			program->window.game.map[y][x] = '0';
		i += 2;
	}
}

/*
** ft_enemy_animate function will animate the enemy
** it will swap the enemy position every 2 frames
*/

static void	ft_enemy_animate(t_program *program)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		swap_enemy(program, 0);
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		swap_enemy(program, 1);
		frame = 0;
	}
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	if (key == ESC_KEY)
		ft_close(program);
	if ((key == RIGHT_KEY || key == D_KEY) || (key == LEFT_KEY || key == A_KEY)
		|| (key == DOWN_KEY || key == S_KEY) || (key == UP_KEY || key == W_KEY))
		return (ft_movements_keyhooks(key, program, program->is_bonus));
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_fill_window(program->mlx, &program->window, program->is_bonus);
	if (program->is_bonus)
	{
		ft_put_display(program);
		ft_enemy_animate(program);
	}
	return (0);
}
