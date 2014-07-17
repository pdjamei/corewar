/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:11:00 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:34:41 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "machine.h"
#include "arena.h"
#include "libft.h"

void	aff(unsigned char *arena, t_champdata *champ)
{
	int	param_1;

	param_1 = gimme_param_value(champ, champ->cmd, 0, arena);
	if (champ->cmd->type_args[0] == 1)
		param_1 = champ->reg[gimme_reg_nbr(param_1)];
	param_1 = param_1 % 256;
	param_1 = ABS(param_1);
	ft_putchar(param_1);
}

int		exec_live(t_champdata *tmp, t_champdata *champ)
{
	if (tmp->pid == champ->reg[0])
	{
		if (!tmp->father)
		{
			ft_putstr("Un processus dit que le joueur ");
			ft_putnbr(tmp->pid);
			ft_putstr("(");
			ft_putstr(tmp->name);
			ft_putstr(") est en vie.\n");
			g_winner_id = tmp->pid;
			g_winner_name = tmp->name;
		}
		tmp->cycle_to_die = 0;
		return (1);
	}
	return (0);
}
