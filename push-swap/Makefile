# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acombe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 15:43:51 by acombe            #+#    #+#              #
#    Updated: 2017/06/21 19:20:18 by acombe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRC1 = ./srcpush/push_swap.c ./srcpush/swapp.c ./srcpush/swaps.c ./srcpush/swop.c ./srcpush/tabfinal.c \
	   ./srcpush/tris.c ./srcpush/tri.c ./srcpush/ft_atoi.c ./srcpush/end.c ./srcpush/forthree.c ./srchecker/ft_is_a_nb.c \
	   ./srchecker/libft/ft_strlen.c ./srchecker/libft/ft_bzero.c ./srcpush/higher.c

SRC2 = ./srchecker/get_next_line.c ./srchecker/check_swapp.c ./srchecker/check_swop.c ./srchecker/check_swaps.c \
	   ./srchecker/checker.c ./srchecker/ft_is_a_nb.c ./srcpush/ft_atoi.c \
	   ./srchecker/libft/ft_strlen.c ./srchecker/libft/ft_bzero.c ./srchecker/begin.c

SRC3 = ./srchecker/libft/libft.a

OBJ = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ2)
	gcc $(FLAGS) -o $(NAME) $(SRC1) $(SRC3)
	gcc $(FLAGS) -o checker $(SRC2) $(SRC3)

clean :
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(OBJ2)

fclean : clean
	/bin/rm -f $(NAME)
	/bin/rm -f checker

re : fclean all
