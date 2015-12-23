# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfelbacq <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 15:45:06 by cfelbacq          #+#    #+#              #
#    Updated: 2015/12/20 16:32:24 by cfelbacq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_arrange.c \
	  ft_check.c \
	  ft_check_shape.c \
	  ft_get_nb_tetrimino.c \
	  ft_readstdin.c \
	  ft_tetrimino.c \
	  ft_solve.c \
	  main.c 

OBJ = $(SRC : .c = .o)

LIB = libft.a

all : $(NAME)

$(NAME) : 
	gcc -Werror -Wall -Wextra -o $(NAME) $(SRC) $(LIB)

clean : 
	rm -rf $(NAME)

fclean : clean

re : fclean all
