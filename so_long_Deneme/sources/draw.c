#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 64, y * 64);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x; //playerı hareket ettireceğimiz için başlangıç konumunu x_player ve y_player içine atıp hareketleri bu intergerlar üzerinden yapacağız.
	game->y_player = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_collect == 0) // toplayacak collect kalmadıysa
	{
		mlx_destroy_image(game->mlx, game->img_exit);  // ilk ev resmini yok eder
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "assets/images/E2.xpm", &game->img_w, &game->img_h);  // evin belirgin göründüğü ikinci resmi basar
	}
	img_draw(game, game->img_exit, x, y);
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])  // haritayı ekrana basma işlemi
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')   
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}