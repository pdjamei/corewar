/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:08:51 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:34:28 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "machine.h"
#include "arena.h"

void	store_index(unsigned char *arena, t_champd *champ)
{
	int				param_1;
	int				param_2;
	int				param_3;
	unsigned char	*tmp;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_3 = gimme_param_value(champ, champ->cmd, 2, arena);
	param_1 = champ->reg[gimme_reg_nbr(param_1)];
	if (champ->cmd->type_args[1] == 1)
		param_2 = champ->reg[gimme_reg_nbr(param_2)];
	if (champ->cmd->type_args[2] == 1)
		param_3 = champ->reg[gimme_reg_nbr(param_3)];
	tmp = champ->pc + (param_2 + param_3) % IDX_MOD;
	tmp = new_adress(tmp, arena);
	stock_convert_nbr(tmp, arena, param_1);
}

void	fork_corewar(unsigned char *arena, t_champd *champ)
{
	int	i;
	int	param_1;

	i = 0;
	if (champ->father > 0)
		return ;
	param_1 = convert_int(champ->cmd->args, 2) % IDX_MOD;
	add_elem(champ);
	champ->prev->pc = new_adress(champ->pc + param_1, arena);
	champ->prev->reg[0] = g_pid;
	champ->prev->pid = g_pid++;
	while (++i < REG_NUMBER)
		champ->prev->reg[i] = champ->reg[i];
	champ->prev->cycle = 0;
	champ->prev->carry = champ->carry;
	champ->prev->father = champ->pid;
	champ->prev->cycle_to_die = champ->cycle_to_die;
	champ->prev->cmd = malloc(sizeof(*(champ->prev->cmd)));
	if (champ->prev->cmd == NULL)
		exit(-1);
	champ->prev->cmd->type_args[0] = 0;
	champ->prev->cmd->type_args[1] = 0;
	champ->prev->cmd->type_args[2] = 0;
}

void	long_load(unsigned char *arena, t_champd *champ)
{
	int	param_1;
	int	param_2;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	param_2 = gimme_param_value(champ, champ->cmd, 1, arena);
	param_2 = gimme_reg_nbr(param_2);
	champ->carry = param_1 ? 0 : 1;
	champ->reg[param_2] = param_1;
}

void	long_load_index(unsigned char *arena, t_champd *champ)
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
	tmp = champ->pc + param_1;
	tmp = new_adress(tmp, arena);
	value = convert_int_instruction(tmp, IND_SIZE, arena) + param_2;
	tmp = champ->pc + value;
	tmp = new_adress(tmp, arena);
	param_3 = gimme_reg_nbr(param_3);
	value = convert_int_instruction(tmp, REG_SIZE, arena);
	champ->carry = value ? 0 : 1;
	champ->reg[param_3] = value;
}

void	long_fork(unsigned char *arena, t_champd *champ)
{
	int	i;
	int	param_1;

	i = 0;
	param_1 = convert_int(champ->cmd->args, 2);
	champ->carry = param_1 ? 0 : 1;
	add_elem(champ);
	champ->prev->pc = new_adress(champ->pc + param_1, arena);
	champ->prev->reg[0] = g_pid;
	champ->prev->pid = g_pid++;
	while (++i < REG_NUMBER)
		champ->prev->reg[i] = champ->reg[i];
	champ->prev->cycle = 0;
	champ->prev->carry = champ->carry;
	champ->prev->father = champ->pid;
	champ->prev->cycle_to_die = champ->cycle_to_die;
	champ->prev->cmd = malloc(sizeof(*(champ->prev->cmd)));
	if (champ->prev->cmd == NULL)
		exit(-1);
	champ->prev->cmd->type_args[0] = 0;
	champ->prev->cmd->type_args[1] = 0;
	champ->prev->cmd->type_args[2] = 0;
}
