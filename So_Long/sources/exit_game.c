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
    ft_printf("\033[1;31m");
    ft_printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    ft_printf(" ┃\033[1;35m       THANK YOU FOR       \033[1;31m┃\n");
    ft_printf(" ┃\033[1;35m           PLAYING        \033[1;31m┃\n");
    ft_printf(" ┃\033[1;35m        THIS AWESOME      \033[1;31m┃\n");
    ft_printf(" ┃\033[1;35m            GAME!         \033[1;31m┃\n");
    ft_printf(" ┃\033[1;35m     INTRA: \033[1;33m%-10s\033[1;35m   \033[1;31m┃\n", game->intra_str);
    ft_printf(" ┃                         ┃\n");
    ft_printf(" ┃\033[1;35m      Press \033[1;33m[Q]\033[1;35m to exit     \033[1;31m┃\n");
    ft_printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	/*game->intra_str = "mulken";
	ft_printf("\n\n------------------------\n\n");
	ft_printf(MAGENTA" THANK YOU FOR PLAYING \n\n"RESET);
	ft_printf(YELLOW"    INTRA: %s \n"RESET, game->intra_str);
	ft_printf(" Press [Q] to exit \n\n");
	ft_printf("------------------------\n");*/
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
