LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/minilibx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

PRINTF_PATH		=	./libraries/ft_printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

X = "\033[34m"
R = "\e[0m"

SOURCES_FILES	=	so_long.c \
					draw.c \
					init.c \
					read_map.c \
					map_validate.c \
					player_update.c \
					gameplay.c \
					exit_game.c

SOURCES_DIR		=	sources

HEADER			=	$(SOURCES_DIR)/so_long.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC				=	clang
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-framework AppKit -framework OpenGL -L./libraries/minilibx -lmlx

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(PRINTF) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

$(PRINTF):
				$(MAKE) -C $(PRINTF_PATH)

norm:				$(SOURCES)
				norminette $(SOURCES) $(HEADER)
				@echo $(X)[--NORMINETTE SUCCES %100--]$(R)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(PRINTF_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(PRINTF_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx norm
