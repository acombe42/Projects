# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acombe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:52:07 by acombe            #+#    #+#              #
#    Updated: 2017/08/17 16:57:09 by acombe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = lem-in

SRC = ./src/main.c ./src/parse.c ./src/parsing.c ./src/get_next_line.c ./src/ft_atoi.c ./src/linkit.c ./src/move.c ./src/pond.c

SRC2 = ./src/libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./src/libft
	gcc $(CFLAGS) -o $(NAME) $(SRC) $(SRC2)

clean :
	/bin/rm -rf $(OBJ)
	make clean -C ./src/libft

fclean : clean
	/bin/rm -f $(NAME)
	make fclean -C ./src/libft

re : fclean all
