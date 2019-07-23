# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsshih <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 14:17:47 by hsshih            #+#    #+#              #
#    Updated: 2019/07/22 14:58:04 by hsshih           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
	  ./srcs/ft_strlen.c ./srcs/ft_swap.c

OFILES = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

INCLUDE = ./includes/

all:
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(INCLUDE)*.h
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f libft.a

re: fclean all
