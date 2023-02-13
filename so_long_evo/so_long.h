/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:42:17 by hsabah            #+#    #+#             */
/*   Updated: 2023/02/06 01:57:03 by hsabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# if defined(__APPLE__) && defined(__MACH__)
#  include "minilibx/mlx.h"
# else
#  include "minilibx-linux/mlx.h"
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ANIMATION_FRAMES 50

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC_KEY 				53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC_KEY				65307
# endif

typedef struct s_size
{
	int	x;
	int	y;
}				t_size;

typedef struct s_image
{
	void		*reference;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	char		*pixels;
	t_size		size;
}				t_image;

typedef struct s_frames
{
	t_image		p;
	t_image		c;
	t_image		e;
	t_image		w;
	t_image		f;
	t_image		k;
}				t_frames;

typedef struct s_map_directions
{
	int			east;
	int			west;
	int			north;
	int			south;
	int			p_and_c_total;
	t_size		seeker;
}				t_map_directions;

typedef struct s_game
{
	char				**map;
	int					**solution;
	int					map_width;
	int					map_height;
	int					collectibles;
	int					exit;
	int					player;
	int					player_x;
	int					player_y;
	int					*enemies_coordinates;
	int					exit_y;
	int					exit_x;
	int					moves_total;
	t_frames			frames;
	t_size				frame_position;
	t_map_directions	map_directions;
}						t_game;

typedef struct s_window
{
	void		*reference;
	t_size		size;
	t_game		game;
}				t_window;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	int			is_bonus;
}				t_program;

void		err_msg(char *msg);

t_window	ft_new_window(t_program *program, char *name);
int			ft_close(t_program *program);

void		ft_check_arg(int argc, char **argv);
void		ft_check_component(char *buffer, t_game *game);
void		ft_check_y_limits(t_game *game);
void		ft_check_x_limits(t_game *game);
void		ft_check_map(char *buffer, t_program *program);

int			ft_map_availability(char **map, int y, int x, t_program *program);
int			ft_redirect_player(char *curr, char *redirected);

int			ft_input(int key, void *param);
int			ft_update(void *param);

void		ft_put_display(t_program *program);
int			ft_movements_keyhooks(int key, t_program *program, int is_bonus);

void		free_map(int **solution, int height);
void		free_map_c(char **solution, int height);
void		map_not_equal_to_program(void);
char		*ft_join(char *line, char c);
char		*ft_get_map(int fd);

void		ft_init_struct(t_program *program, int is_bonus);
void		define_frames(t_program *program);
void		ft_reset_program(t_program program);

int			solvemaze(t_game *game, int r, int c, char **solution);
int			access_to_collectibles(t_game *game, char **v_map);
void		find_path(t_game *game);

t_image		ft_img(void *mlx, char *path);
void		ft_fill_window(void *mlx, t_window *window, int is_bonus);

void		set_solution_map_to_int(t_game *game);

void		ft_is_map_char(char c);
void		ft_limits_error(void);
void		ft_file_is_open(int fd);
void		ft_small_map(t_game *game);
void		ft_path_is_ok(int W, int K, int y);

void		ft_validate_map(char **argv, t_program *program);

#endif