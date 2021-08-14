# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligeorgi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 11:56:55 by ligeorgi          #+#    #+#              #
#    Updated: 2019/10/24 11:57:21 by ligeorgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	./main.c	\
	./print.c 	\
	./fill_field.c 	\
	./read.c 	\
	./get_figure.c 	\

OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	gcc -o fillit $(OBJS) -I libft -L libft/ -lft

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
