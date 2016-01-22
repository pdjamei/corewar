/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 16:10:26 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:18:08 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "arena.h"
#include "libft.h"

void			check_inst(t_champd *tmp, unsigned char *arena)
{
	if (*tmp->pc > 0 && *tmp->pc < 17)
	{
		tmp->cycle = g_funct_tab[*tmp->pc - 1].cycles;
		instruct(tmp, arena);
	}
	else
		tmp->pc = new_adress(tmp->pc + 1, arena);
}

void			exec_inst(t_champd *tmp, unsigned char *arena,
		t_cycle *cycle)
{
	int			arg;

	if (spec_func(tmp, arena))
		arg = 1;
	else
		arg = 2;
	arg = arg + tmp->cmd->type_args[0];
	arg = arg + tmp->cmd->type_args[1];
	arg = arg + tmp->cmd->type_args[2];
	g_funct_tab[tmp->cmd->funct - 1].function(arena, tmp);
	tmp->cmd->type_args[0] = 0;
	tmp->cmd->type_args[1] = 0;
	tmp->cmd->type_args[2] = 0;
	if (tmp->cmd->funct == 9 && tmp->carry)
		return ;
	else if (tmp->cmd->funct == 1)
		cycle->nbr_live++;
	tmp->pc = new_adress(tmp->pc + arg, arena);
}

void			check_cycle(t_champd *tmp, unsigned char *arena, t_cycle
		*cycle)
{
	if (tmp->cycle == 0)
		check_inst(tmp, arena);
	else if (--tmp->cycle == 1)
	{
		exec_inst(tmp, arena, cycle);
		tmp->cycle = 0;
	}
}

static void		end(int nbr, unsigned char *arena, t_champd *champ,
		t_cycle *cycle)
{
	if (nbr == 0)
		ft_dump(arena, champ, cycle);
	else
	{
		ft_putstr("Winner is : ");
		ft_putstr(g_winner_name);
		ft_putstr(" (player ");
		ft_putnbr(g_winner_id);
		ft_putstr(")\n");
	}
}

void			launch_battle(int nbr, unsigned char *arena,
		t_champd *champ, t_cycle *cycle)
{
	t_champd	*tmp;
	int			i;

	i = 0;
	while (cycle->cycle_to_die > 0 && check_round(champ, cycle) && nbr != 0)
	{
		tmp = champ->next;
		while (tmp != champ)
		{
			check_cycle(tmp, arena, cycle);
			tmp->cycle_to_die = tmp->cycle_to_die + 1;
			tmp = tmp->next;
			if (cycle->nbr_live >= NBR_LIVE)
			{
				cycle->cycle_to_die = cycle->cycle_to_die - CYCLE_DELTA;
				cycle->nbr_live = 0;
				i = 0;
			}
		}
		nbr--;
		cycle->current_cycle = cycle->current_cycle + 1;
		if (++i >= MAX_CHECKS)
			(cycle->cycle_to_die)--;
	}
	end(nbr, arena, champ, cycle);
}
