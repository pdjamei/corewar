/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/05 11:04:34 by pdjamei           #+#    #+#             */
/*   Updated: 2015/10/05 11:05:19 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "arena.h"
#include "libft.h"


void			ft_dump(unsigned char *arena, t_champdata *champ, t_cycle *cycle)
{
	write(1, arena, MEM_SIZE);
	(void)champ;
	(void)cycle;
}