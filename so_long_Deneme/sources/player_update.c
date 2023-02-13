#include "so_long.h"

void eventsuccess(t_game *game)
{
	game->intra_str = "mulken";
	printf("\n\n-------------------\n\n");
	printf(MAGENTA"THANK YOU FOR PLAYING\n\n"RESET);
	printf(YELLOW"    INTRA: %s\n"RESET,game->intra_str);
	printf(" Press [Q] to exit\n\n");
	printf("-------------------\n");
}

static void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);  //oyuncunun hareket ettiği yöne göre baktığı yön değişeceği için eski image i yok edip yeni image basar
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PW.xpm", &game->img_w, &game->img_h);  //w veya d ise yani sağ ya da yukarı gidecekse yönü sağa bakar
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PS.xpm", &game->img_w, &game->img_h); //s veya a ise yani sol ya da aşağı gidecekse yönü sola bakar.
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PD.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "assets/images/PA.xpm", &game->img_w, &game->img_h);
/* 	else if (key == 'h')
	{
		mlx_new_window
	} */
}

void	player_w(t_game *game)
{
	player_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == 'E'  // w ye basınca y bir birim azalacak yeni harekte edeceği kutucuk E ise ve toplayacağı bir şey kalmadıysa oyun bitecek
			&& game->n_collect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_player + 1][game->x_player] = '0'; // playerın eski yerine background koyacak
		game->moves++;
		game->endgame = 1; // endgame 1 yaptık o zaman if(!1) olacak ve keypresste kontrol yapmıştık. return(0) olacak
		map_draw(game); // haritayı tekrar düzenlemeye gönderiyoruz
		}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')  // gideceği yer duvar veya çıkışsa eski konumunda dursun diye y yi arttırdık(önce azaltmıştık bir kere çünkü)
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);  // yukarıdakilerin hiçbiri değilse pencereyi bir temizleyelim
		if (game->map[game->y_player][game->x_player] == 'C')  // coinse collecti bir azaltıp toplayalım.(collect içinde toplam sayıyı tutuyor)
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P'; // player yeni yerine atanıyor
		game->map[game->y_player + 1][game->x_player] = '0'; // playerın eski yeri background oluyor
		game->moves++;
		map_draw(game); // harita güncellemeye gidiyor
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
