# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:14:39 by mcassagn          #+#    #+#              #
#    Updated: 2014/06/15 20:41:52 by pdjamei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -O3 -I./includes -g
SRC =   ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_putchar_fd.c \
	  ft_putchar.c \
	  ft_putstr_fd.c \
	  ft_putstr.c \
	  ft_putendl_fd.c \
	  ft_putendl.c \
	  ft_itoa.c \
	  ft_putnbr_fd.c \
	  ft_putnbr.c \
	  ft_strnew.c \
	  ft_memdel.c \
	  ft_strdel.c \
	  ft_memalloc.c \
	  ft_strclr.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_putstr_fd.c \
	  ft_strrev.c \
	  ft_strndup.c \
	  ft_realloc.c \
	  ft_power.c \
	  get_next_line.c	\


OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

.c.o:
	@$(CC) -c -I./includes $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@echo "Making $(NAME) objects files"
	@echo "Making $(NAME) library"
	@ar -q $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library $(NAME) created"

clean:
	@echo "Deleting $(NAME) objects files"
	@rm -rf $(OBJ)

fclean:		clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean all re clean
