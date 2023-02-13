/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:40:52 by hsabah            #+#    #+#             */
/*   Updated: 2023/01/30 23:31:27 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_program	program;

	ft_check_arg(argc, argv);
	ft_init_struct(&program, 1);
	ft_validate_map(argv, &program);
	program.mlx = mlx_init();
	program.window = ft_new_window(&program, "So Long Bonus");
	define_frames(&program);
	mlx_hook(program.window.reference, 2,
		1L << 0, *ft_input, &program);
	mlx_hook(program.window.reference, 17,
		1L << 5, ft_close, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
	ft_reset_program(program);
	exit(1);
	return (1);
}
