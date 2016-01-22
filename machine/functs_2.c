/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:07:25 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:33:51 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	and(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		param_2 = champ->reg[gimme_reg_nbr(param_2)];
	param_3 = gimme_reg_nbr(param_3);
	champ->carry = (param_1 & param_2) ? 0 : 1;
	champ->reg[param_3] = param_1 & param_2;
}

void	or(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		param_2 = champ->reg[gimme_reg_nbr(param_2)];
	param_3 = gimme_reg_nbr(param_3);
	champ->carry = (param_1 | param_2) ? 0 : 1;
	champ->reg[param_3] = param_1 | param_2;
}

void	xor(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;
	int	param_3;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		param_2 = champ->reg[gimme_reg_nbr(param_2)];
	param_3 = gimme_reg_nbr(param_3);
	champ->carry = (param_1 ^ param_2) ? 0 : 1;
	champ->reg[param_3] = param_1 ^ param_2;
}

void	jump(unsigned char *arena, t_champd *champ)
{
	int		result;

	if (champ->carry == 0)
		return ;
	result = convert_int(champ->cmd->args, champ->cmd->type_args[0]);
	champ->pc = new_adress(champ->pc + result, arena);
}

void	load_index(unsigned char *arena, t_champd *champ)
{
	int				param_1;
	int				param_2;
	int				param_3;
	unsigned char	*tmp;
	int				value;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		param_2 = champ->reg[gimme_reg_nbr(param_2)];
	tmp = champ->pc + param_1 % IDX_MOD;
	tmp = new_adress(tmp, arena);
	value = convert_int_instruction(tmp, IND_SIZE, arena) + param_2;
	tmp = champ->pc + value % IDX_MOD;
	tmp = new_adress(tmp, arena);
	param_3 = gimme_reg_nbr(param_3);
	value = convert_int_instruction(tmp, REG_SIZE, arena);
	champ->carry = value ? 0 : 1;
	champ->reg[param_3] = value;
}
