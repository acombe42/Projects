# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 15:03:20 by bait-sli          #+#    #+#              #
#    Updated: 2017/02/16 03:04:57 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS= -Wall -Wextra -Werror #-g3 -fsanitize=address

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I ./ -I ../include/

SRC=ft_lstiter.c ft_putchar_fd.c ft_strdel.c ft_strncpy.c\
	ft_atoi.c ft_lstmap.c ft_putendl.c ft_strdup.c ft_strnequ.c\
	ft_bzero.c ft_lstnew.c ft_putendl_fd.c ft_strequ.c ft_strnew.c\
	ft_isalnum.c ft_memalloc.c ft_putnbr.c ft_striter.c ft_strnstr.c\
	ft_isalpha.c ft_memccpy.c ft_putnbr_fd.c ft_striteri.c ft_strrchr.c\
	ft_isascii.c ft_memchr.c ft_putstr.c ft_strjoin.c ft_strsplit.c\
	ft_isdigit.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strstr.c\
	ft_isprint.c ft_memcpy.c ft_strcat.c ft_strlen.c ft_strsub.c\
	ft_itoa.c ft_memdel.c ft_strchr.c ft_strmap.c ft_strtrim.c\
	ft_lstadd.c ft_memmove.c ft_strclr.c ft_strmapi.c ft_tolower.c\
	ft_lstdel.c ft_memset.c ft_strcmp.c ft_strncat.c ft_toupper.c\
	ft_lstdelone.c ft_putchar.c ft_strcpy.c ft_strncmp.c get_next_line.c\

OBJ=$(SRC:.c=.o)

$(NAME): ./libft.h
		$(CC) -g $(CFLAGS) -c $(SRC) $(HDDIRS)
			ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
