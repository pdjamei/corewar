# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/15 17:18:59 by mcassagn          #+#    #+#              #
#    Updated: 2014/06/18 16:05:24 by pdjamei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : asm vm

asm :
	make -C assembleur
	@mv assembleur/asm ./asm

vm  :
	make -C machine
	@mv machine/corewar ./corewar

clean :
	make -C assembleur clean

fclean :
	rm -rf asm corewar
	make -C assembleur fclean

re: fclean all

.PHONY: asm vm fclean clean re
