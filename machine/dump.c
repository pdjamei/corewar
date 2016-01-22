/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:04:34 by pdjamei           #+#    #+#             */
/*   Updated: 2015/10/05 11:05:19 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "arena.h"
#include "libft.h"

static void	ft_puthex(unsigned char c)
{
	if ((c / 16) < 10)
		ft_putnbr(c / 16);
	else
		ft_putchar('A' + c / 16 - 10);
	if (c % 16 < 10)
		ft_putnbr(c % 16);
	else
		ft_putchar('A' + c % 16 - 10);
}

void		ft_dump(unsigned char *arena, t_champd *champ, t_cycle *cycle)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 32 != 31)
		{
			ft_putnbr(0);
			ft_putchar('x');
			ft_puthex(arena[i]);
			ft_putchar(' ');
		}
		else
		{
			ft_putnbr(0);
			ft_putchar('x');
			ft_puthex(arena[i]);
			ft_putchar('\n');
		}
		i++;
	}
	(void)champ;
	(void)cycle;
}
