/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsubfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 19:35:54 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:35:33 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arena.h"

int		gimme_reg_nbr(int reg)
{
	reg -= 1;
	reg = ((reg >= 0) ? reg : -reg);
	reg = reg % REG_NUMBER;
	return (reg);
}

int		gimme_param_value(t_champd *champ, t_cmd *cmd,
							int arg, unsigned char *arena)
{
	int				i;
	int				place;
	unsigned char	*tmp;

	i = 0;
	place = 0;
	while (i < arg)
		place += cmd->type_args[i++];
	if (cmd->type_args[arg] == 1)
		return (cmd->args[place]);
	else if (cmd->type_args[arg] == 4)
		return (convert_int(cmd->args + place, cmd->type_args[arg]));
	else
	{
		i = convert_int(cmd->args + place, cmd->type_args[arg]);
		if (cmd->funct > 12)
			tmp = champ->pc + i;
		else
			tmp = champ->pc + (i % IDX_MOD);
		tmp = new_adress(tmp, arena);
		return (convert_int_instruction(tmp, 4, arena));
	}
}

void	add_elem(t_champd *root)
{
	t_champd	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (new_elem == NULL)
		exit(-1);
	new_elem->next = root;
	new_elem->prev = root->prev;
	root->prev->next = new_elem;
	root->prev = new_elem;
}
