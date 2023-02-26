/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:59:44 by mulken            #+#    #+#             */
/*   Updated: 2023/02/22 13:59:45 by mulken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eventsuccess(t_game *game)
{
	game->intra_str = "mulken";
	ft_printf("\033[1;35m\n");
	ft_printf(" ____________________________ \n");
	ft_printf("|                            | \n");
	ft_printf("|       THANK YOU FOR        |\n");
	ft_printf("|           PLAYING          |\n");
	ft_printf("|        THIS AWESOME        |\n");
	ft_printf("|            GAME!           |\n");
	ft_printf("|       INTRA: \033[1;33m%s\033[1;35m        |\n", game->intra_str);
	ft_printf("|____________________________|\e[0m \n\n");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}
