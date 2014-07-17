/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:20:05 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:31:57 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arena.h"

void	remove_champ(t_champdata *champ)
{
	if (champ)
	{
		if (champ->name)
			free(champ->name);
		if (champ->comment)
			free(champ->comment);
		if (champ->parsing)
		{
			if (champ->parsing->code_content)
				free(champ->parsing->code_content);
			free(champ->parsing);
		}
		if (champ->prev)
			champ->prev->next = champ->next;
		if (champ->next)
			champ->next->prev = champ->prev;
		if (champ->cmd)
			free(champ->cmd);
	}
}

void	remove_level(t_champdata *champ, t_champdata *tmp)
{
	t_champdata	*tmp2;

	tmp2 = champ;
	while (tmp2 != champ->prev)
	{
		if (tmp2->prev != tmp && tmp2->prev->father == tmp->pid)
			remove_level(champ, tmp2->prev);
		tmp2 = tmp2->next;
	}
	if (tmp2->prev != tmp && tmp2->prev && tmp2->prev->father == tmp->pid)
		remove_level(champ, tmp2->prev);
	remove_champ(tmp);
}
