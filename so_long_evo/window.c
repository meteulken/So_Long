/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:54:10 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/31 15:08:53 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_program *program)
{
	mlx_clear_window(program->mlx, program->window.reference);
	mlx_destroy_window(program->mlx, program->window.reference);
	exit(0);
	return (0);
}

t_window	ft_new_window(t_program *program, char *name)
{
	program->window.size.x = program->window.game.map_width * ANIMATION_FRAMES;
	program->window.size.y = program->window.game.map_height * ANIMATION_FRAMES;
	program->window.reference = mlx_new_window(program->mlx,
			program->window.size.x, program->window.size.y, name);
	return (program->window);
}
