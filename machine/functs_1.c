/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:06:04 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:33:22 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	live(unsigned char *arena, t_champd *champ)
{
	t_champd	*tmp;

	(void)arena;
	tmp = champ;
	if (exec_live(tmp, champ))
		return ;
	tmp = tmp->next;
	while (tmp != champ)
	{
		if (exec_live(tmp, champ))
			return ;
		tmp = tmp->next;
	}
}

void	load(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_2 = gimme_reg_nbr(param_2);
	champ->carry = param_1 ? 0 : 1;
	champ->reg[param_2] = param_1;
}

void	store(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		champ->reg[gimme_reg_nbr(param_2)] = param_1;
	else if (champ->cmd->type_args[1] == 2)
	{
		param_2 = convert_int(champ->cmd->args + champ->cmd->type_args[0], 2);
		stock_convert_nbr(champ->pc + param_2, arena, param_1);
	}
}

void	add(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	param_1 = champ->reg[gimme_reg_nbr(param_1)];
	param_2 = champ->reg[gimme_reg_nbr(param_2)];
	param_3 = gimme_reg_nbr(param_3);
	champ->carry = (param_1 + param_2) ? 0 : 1;
	champ->reg[param_3] = param_1 + param_2;
}

void	sub(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	param_1 = champ->reg[gimme_reg_nbr(param_1)];
	param_2 = champ->reg[gimme_reg_nbr(param_2)];
	param_3 = gimme_reg_nbr(param_3);
	champ->carry = (param_1 - param_2) ? 0 : 1;
	champ->reg[param_3] = param_1 - param_2;
}
