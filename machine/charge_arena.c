/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:51:57 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:18:56 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "arena.h"
#include "libft.h"

void				put_content(t_champd *champ)
{
	int				i;

	i = -1;
	while (++i < champ->parsing->size && i < MEM_SIZE)
		champ->pc[i] = champ->parsing->code_content[i];
}

int					sum_memchamp(t_champd *champdata)
{
	t_champd		*tmp;
	int				ret;

	tmp = champdata->next->next;
	ret = 0;
	while (tmp != champdata)
	{
		ret = ret + tmp->parsing->size;
		tmp = tmp->next;
	}
	return (ret);
}

int					nbr_champ(t_champd *champdata)
{
	int				i;
	t_champd		*tmp;

	i = 0;
	tmp = champdata->next;
	while (tmp != champdata)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void				charge_champs(t_champd *champdata, unsigned char *arena)
{
	t_champd		*tmp;
	int				pos;
	int				mem_left;
	int				margin;
	int				sum_mem_champs;

	pos = 0;
	tmp = champdata->next;
	mem_left = MEM_SIZE - tmp->parsing->size;
	sum_mem_champs = sum_memchamp(champdata);
	if (sum_mem_champs > mem_left)
		exit(-1);
	margin = ((mem_left - sum_mem_champs) / nbr_champ(champdata));
	tmp = tmp->next;
	while (tmp != champdata)
	{
		pos = pos + margin + tmp->prev->parsing->size;
		tmp->pc = &(arena[pos]);
		put_content(tmp);
		tmp = tmp->next;
	}
}

void				charge_param(t_champd *champdata, unsigned char *arena)
{
	champdata->next->pc = &(arena[0]);
	put_content(champdata->next);
	if (champdata->next->next != champdata)
		charge_champs(champdata, arena);
}
