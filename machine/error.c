/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:53:00 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 20:16:06 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "machine.h"
#include "libft.h"

void		ft_exit(t_champ *champ)
{
	t_champ	*tmp;

	ft_putstr("Usage : ./corewar [-dump nbr_cycles] [[-n number] ");
	ft_putstr("champion1.cor] ...\n");
	while (champ)
	{
		tmp = champ;
		champ = champ->next;
		if (tmp->file)
			free(tmp->file);
		if (tmp)
			free(tmp);
	}
	exit(1);
}
