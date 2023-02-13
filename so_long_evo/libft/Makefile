# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsabah <hakkisabah@hotmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:20:39 by hsabah            #+#    #+#              #
#    Updated: 2023/01/08 23:32:33 by hsabah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PREFIX_AND_NAME

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm
AR			=	ar rcs

#SOURCES

BONUSF = $(wildcard ft_lst*.c)

ALLFILES = $(wildcard *.c)

FILES = $(filter-out $(BONUSF), $(ALLFILES))


#MERGE

OBJ			=	$(FILES:.c=.o)

B_OBJ			=	$(BONUSF:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo $(OBJ)
	@echo Objects build started..
	$(AR) $(NAME) $(OBJ)
	@echo Objects builded !

bonus: $(OBJ) $(B_OBJ)
	@echo $(BONUSF)
	$(AR) $(NAME) $(OBJ) $(B_OBJ)
	@echo Bonus object builded !

clean:
	@echo Cleaning
	@$(RM) -rf $(OBJ) $(B_OBJ)
	@echo Cleanin end!

fclean: clean
	@echo Force cleaning..
	@$(RM) -f $(NAME)
	@echo Force cleaning end!

re: fclean all

.PHONY: all clean fclean re bonus
