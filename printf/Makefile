# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acombe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:01:30 by acombe            #+#    #+#              #
#    Updated: 2017/05/13 17:26:00 by acombe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ./src/ft_atoi.c ./src/ft_isdigit.c ./src/ft_itoa.c ./src/ft_itoa_base_x.c ./src/ft_printf.c \
	  ./src/ft_putstr.c ./src/ft_strjoin.c ./src/ft_strjoinxfree.c ./src/ft_strlen.c \
	  ./src/ft_toupper.c ./src/ft_unicode.c ./src/ft_itoa_base_lx.c ./src/ft_litoa.c ./src/ft_hitoa.c \
	  ./src/ft_hhitoa.c ./src/ft_itoa_base_hx.c ./src/ft_itoa_base_hhx.c ./src/ft_parsing.c ./src/ft_xoup.c\
	  ./src/ft_did.c ./src/ft_cc.c ./src/ft_carac.c ./src/ft_number.c ./src/ft_numbertwo.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean : 
	/bin/rm -rf $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
