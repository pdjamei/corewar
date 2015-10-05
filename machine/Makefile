 #**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:14:39 by mcassagn          #+#    #+#              #
#    Updated: 2014/07/17 16:26:39 by pdjamei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
CFLAGS =	-g -Wall -Wextra -Werror
LDFLAGS =	-L ../libft -lft
INCL =		-I ../includes
LIB =		libft.a
SRC =   	battle.c\
			dump.c\
			champ_create.c\
			champ_number.c\
			charge_arena.c\
			convert_func.c\
			destroy.c\
			for_check.c\
			for_negative.c\
			functs_1.c\
			functs_2.c\
			functs_3.c\
			functs_4.c\
			match.c\
			error.c\
			prepare_champ.c\
			subsubfunc.c\
			main.c

OBJ = $(SRC:.c=.o)
NAME = corewar

all: $(NAME)

$(LIB):
	make -C ../libft

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@ $(INCL)

$(NAME): $(LIB) $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C ../libft clean
	rm -rf $(OBJ)

fclean:		clean
	make -C ../libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all re clean
