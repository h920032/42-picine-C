# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsshih <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/27 15:09:03 by hsshih            #+#    #+#              #
#    Updated: 2019/07/28 01:03:32 by hugoshih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.c ft_putchar.c rush00.c rush01.c rush02.c rush03.c rush04.c \
	   ft_putchar_inarray.c ft_strlen.c ft_strcmp.c ft_putstr.c ft_atoi.c \
	   ft_putnbr.c ft_import_stdin.c

NAME_TWO = ft_putchar.c rush00.c rush01.c rush02.c rush03.c rush04.c \
			ft_putchar_inarray.c ft_strlen.c ft_strcmp.c ft_putstr.c ft_atoi.c

SRCS = ft_header.h

all:
	@gcc -Wall -Werror -Wextra -o colle-2 -I $(SRCS) $(NAME)

clean:
	@rm -f colle-2

fclean: clean

rush00:
	@gcc -Wall -Werror -Wextra -o colle-00 main_00.c $(NAME_TWO)

rush01:
	@gcc -Wall -Werror -Wextra -o colle-01 main_01.c $(NAME_TWO)

rush02:
	@gcc -Wall -Werror -Wextra -o colle-02 main_02.c $(NAME_TWO)

rush03:
	@gcc -Wall -Werror -Wextra -o colle-03 main_03.c $(NAME_TWO)

rush04:
	@gcc -Wall -Werror -Wextra -o colle-04 main_04.c $(NAME_TWO)
