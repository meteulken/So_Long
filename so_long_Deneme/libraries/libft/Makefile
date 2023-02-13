NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC =		ft_strjoin.c \
		ft_strdup.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_split.c \
		ft_itoa.c \
		ft_strlcpy.c \
		get_next_line.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
