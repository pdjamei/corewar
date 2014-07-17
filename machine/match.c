/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:46:06 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 21:58:59 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "machine.h"
#include "arena.h"
#include "libft.h"

unsigned char		*instal_arena(void)
{
	unsigned char	*arena;

	if (!(arena = (unsigned char *)malloc(MEM_SIZE * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(arena, MEM_SIZE * sizeof(unsigned char));
	return (arena);
}

t_cycle				*init_cycle(void)
{
	t_cycle			*cycle;

	if (!(cycle = (t_cycle *)malloc(sizeof(t_cycle))))
		return (NULL);
	cycle->nbr_live = 0;
	cycle->current_cycle = 1;
	cycle->cycle_to_die = CYCLE_TO_DIE;
	return (cycle);
}

void				launch_match(int nbr_cycle, t_champ *champ)
{
	unsigned char	*arena;
	t_cycle			*cycle;
	t_champdata		*champdata;

	g_pid = 5;
	g_winner_id = 0;
	g_winner_name = NULL;
	arena = instal_arena();
	cycle = init_cycle();
	champdata = ready_champ_for_arena(champ);
	charge_param(champdata, arena);
	launch_battle(nbr_cycle, arena, champdata, cycle);
}
