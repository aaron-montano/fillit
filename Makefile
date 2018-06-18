# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amontano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 19:46:49 by amontano          #+#    #+#              #
#    Updated: 2018/05/25 20:08:46 by amontano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC =	ft_lib.c\
		main.c\
		map.c\
		map_util.c\
		shift_etris.c\
		solve.c\
		solve_util.c\
		t_etris.c\
		valid.c

OBJ = $(SRC:.c=.o)
SRC_PATH = src/
SRC_POS = $(addprefix $(SRC_PATH), $(SRC))
INC = -I includes/fillit.h
LIBFT = src/libft/libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(INC)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	make -C ./src/libft

clean:
	rm -f $(OBJ)
		make clean -C src/libft

fclean: clean
	rm -f $(NAME)
		make fclean -C src/libft

re: fclean all

.PHONY: all, re, clean, fclean

