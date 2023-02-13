#include "so_long.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'  //map dosyası .ber uzantılı mı kontrolü yapıyor.
		&& argv [i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (map_checker(&game) && argv_checker(argv[1]))
		{
			game_init(&game);
			gameplay(&game);
			mlx_loop(game.mlx); // eventları beklerken pencereyi infinite loopta tutar.
			
		}
		else
		{
			if (game.map)
				free_map(game.map);
			printf("Error\nInvalid Map");
			exit(1); // sorunsuz çıkışta exit(0) kullanılır 0dan farklı bir değer alması errorlu çıkış olduğunu gösterir.
		}
	}
	else
	{
		printf("Error\nInvalid Syntax");
		exit(1);
	}
	return (0);
}
