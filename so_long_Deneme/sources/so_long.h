#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx/mlx.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    void    *img_backg;
    void    *img_wall;
    void    *img_player;
    void    *img_collect;
    void    *img_exit;
    void    *img_losing;
    int        map_w;
    int        map_h;
    int        img_w;
    int        img_h;
    int        n_collect;
    char    *intra_str;
    int        n_player;
    int        n_exit;
    int        x_player; // playerın x eksenindeki konumu
    int        y_player; // playerın y eksenindeki konumu
    int        moves;
    int        endgame;
}    t_game;

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define COLOR_SILVER	0x000000
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define BLUE		"\x1b[34m"
# define YELLOW		"\x1b[33m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"

# define RESET		"\x1b[0m"

void    img_draw(t_game *game, void *image, int x, int y);
int        map_draw(t_game *game);
void    game_init(t_game *game);
char    **read_map(char *path);
int        map_checker(t_game *game);
void    gameplay(t_game *game);
void    player_w(t_game *game);
void eventsuccess(t_game *game);
void    player_d(t_game *game);
void    player_s(t_game *game);
void    player_a(t_game *game);
int        exit_game(t_game *game);
void    free_map(char **map);

#endif
