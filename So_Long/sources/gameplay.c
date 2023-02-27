/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:59:22 by mulken            #+#    #+#             */
/*   Updated: 2023/02/22 13:59:25 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_step_count(t_game *game)
{
	char *str;
	char *step_str;
	char *new_str;

	step_str = "Step Count: ";
	str = ft_itoa(game->moves);
	new_str = ft_strjoin(step_str, str);
	mlx_string_put(game->mlx, game->win, 20, 20, 0x000000, new_str);
	free(str);
	free(new_str);
}

void	draw_collect_count(t_game *game)
{
	char	*str;
	char	*collect_str;
	char	*new_str;

	collect_str = "Collect Count: ";
	str = ft_itoa(game->n_collect);
	new_str = ft_strjoin(collect_str, str);
	mlx_string_put(game->mlx, game->win, 20, 40, 0x000000, new_str);
	free(str);
	free(new_str);
}

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
		draw_step_count(game);
		draw_collect_count(game);
		if (game->endgame == 1)
		{
			eventsuccess(game);
			exit_game(game);
		}
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}
