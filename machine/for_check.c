/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:21:01 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:32:37 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

t_tab	g_funct_tab[] =
{
	{10, live},
	{5, load},
	{5, store},
	{10, add},
	{10, sub},
	{6, and },
	{6, or },
	{6, xor},
	{20, jump},
	{25, load_index},
	{25, store_index},
	{800, fork_corewar},
	{10, long_load},
	{50, long_load_index},
	{1000, long_fork},
	{2, aff},
};

unsigned char	*new_adress(unsigned char *next, unsigned char *arena)
{
	unsigned char	*new;

	new = next;
	if ((long)new >= (long)arena + MEM_SIZE)
	{
		new = (unsigned char *)((long)new - (long)arena);
		new = (unsigned char *)((long)new % (long)MEM_SIZE);
		new = (unsigned char *)((long)new + (long)arena);
	}
	else if ((long)new < (long)arena)
	{
		new = (unsigned char *)((long)new % (long)MEM_SIZE);
		new = (unsigned char *)((long)new + (long)arena);
	}
	return (new);
}

void			is_args(t_champdata *champ, unsigned char *arena)
{
	int				i;
	int				size;
	unsigned char	*tmp;

	size = champ->cmd->type_args[0] + champ->cmd->type_args[1];
	size = size + champ->cmd->type_args[2];
	i = -1;
	while (++i < size)
	{
		tmp = new_adress(champ->PC + 2 + i, arena);
		champ->cmd->args[i] = tmp[0];
	}
}

void			is_args_type(t_champdata *tmp, char *args_type)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (args_type[i] || args_type[i + 1])
		{
			if (args_type[i] && args_type[i + 1])
				tmp->cmd->type_args[i / 2] = IND_SIZE;
			else if (args_type[i])
				tmp->cmd->type_args[i / 2] = DIR_SIZE;
			else
				tmp->cmd->type_args[i / 2] = T_REG;
		}
		i = i + 2;
	}
}

int				spec_func(t_champdata *tmp, unsigned char *arena)
{
	unsigned char	*tmpa;

	if (tmp->cmd->funct == 1)
		tmp->cmd->type_args[0] = 4;
	else if (tmp->cmd->funct == 9 || tmp->cmd->funct == 12
			|| tmp->cmd->funct == 15)
	{
		tmp->cmd->type_args[0] = 2;
		tmpa = new_adress(tmp->PC + 1, arena);
		tmp->cmd->args[0] = tmpa[0];
		tmpa = new_adress(tmp->PC + 2, arena);
		tmp->cmd->args[1] = tmpa[0];
	}
	else
		return (0);
	return (1);
}

void			instruct(t_champdata *tmp, unsigned char *arena)
{
	unsigned char	*tmpa;
	char			args_type[8];

	tmp->cmd->funct = tmp->PC[0];
	if (spec_func(tmp, arena))
		return ;
	tmpa = new_adress(tmp->PC + 1, arena);
	convert_dectbin(tmpa[0], args_type);
	is_args_type(tmp, args_type);
	is_args(tmp, arena);
}
