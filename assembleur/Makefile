# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:14:39 by mcassagn          #+#    #+#              #
#    Updated: 2014/06/15 17:44:30 by mcassagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -pedantic -O3 -I ../includes -g
LFLAGS	=	-L ../libft -lft
SRC		=   assembleur.c\
			check_syntax.c\
			check_type.c\
			check_type2.c\
			free.c\
			ft_error.c\
			get.c\
			get_2.c\
			list.c\
			op.c\
			parse_line.c\
			tools_1.c\
			tools_2.c\
			write.c\
			write_header.c
OBJS	=	$(SRC:.c=.o)
NAME 	=	asm

all		:	$(NAME)

.c.o	:
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME)	:	$(OBJS)
	@echo "Making $(NAME) objects files"
	@echo "Making libft.a library needed by $(NAME)"
	@make -C ../libft
	@echo "Making $(NAME) executable file"
	@gcc -o $(NAME) $(OBJS) $(LFLAGS)

clean	:
	@make -C ../libft clean
	@rm -rf $(OBJS)

fclean	:	clean
	@make -C ../libft fclean
	@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	fclean all re clean
