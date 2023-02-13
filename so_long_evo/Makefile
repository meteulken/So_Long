# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:50:54 by hsabah            #+#    #+#              #
#    Updated: 2023/01/30 14:55:39 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname)
LIBFTPATH		= libft

NAME		= so_long
HEADER		= so_long.h

BNAME		= so_long_bonus
BHEADER		= so_long_bonus.h

# For MacOS
MINILIBX	= minilibx/
# For Linux
ifeq ($(OS),Linux)
    MINILIBX = minilibx-linux/
endif

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
FSANITIZE	= -fsanitize=address -g3
RM			= rm -f
ECHO		= echo


# For MacOS
OPENGL		= -framework OpenGL -framework AppKit

# For MacOS
MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx
# For Linux
ifeq ($(OS),Linux)
    MINILIBXCC	= -lmlx -lXext -lX11 -lm -lbsd
endif

COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a $(MINILIBX)/libmlx.a
COMPILEPRMB	= $(MINILIBXCC) $(OPENGL) -o $(BNAME) libft.a $(MINILIBX)/libmlx.a
ifeq ($(OS),Linux)
COMPILEPRM	= $(HEADER) $(MINILIBXCC) libft.a -o $(NAME)
COMPILEPRMB = $(BHEADER) $(MINILIBXCC) libft.a -o $(BNAME)
endif

ALLFILES = $(wildcard *.c)

MANDATORYFILES	= $(filter-out so_long_bonus.c, $(ALLFILES))
BONUSFILES		= $(filter-out so_long.c, $(ALLFILES))

MANDATORYOBJ	=	$(MANDATORYFILES:.c=.o)
BONUSOBJ		=	$(BONUSFILES:.c=.o)

start:
			@make all

all:		$(NAME)

$(NAME):	$(MANDATORYOBJ)
			@make -s -C $(MINILIBX)
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(MANDATORYOBJ) $(COMPILEPRM)

bonus:		$(BNAME)

$(BNAME):	$(BONUSOBJ)
			@make -s -C $(MINILIBX)
			@make -C $(LIBFTPATH)
			@make bonus -C $(LIBFTPATH)
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(BONUSOBJ) $(COMPILEPRMB)

clean:
			@$(RM) -r $(MANDATORYOBJ)
			@$(RM) -r $(NAME)
			@$(RM) -r $(BONUSOBJ)
			@$(RM) -r $(BNAME)
			@make clean -C $(MINILIBX)
			@make clean -C $(LIBFTPATH)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -rf libft.a


re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

.PHONY:		all clean fclean re norm
