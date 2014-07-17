/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:52:15 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 20:16:36 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "machine.h"

int			ft_isintab(int *tab, int len, int nbr)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (tab[i] == nbr)
			return (1);
	}
	return (0);
}

int			*modif_tab(int *tab, int len)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 1;
	while (i < len)
	{
		if (tab[i] != -1)
			i++;
		else if (ft_isintab(tab, len, nbr) == 1)
			nbr++;
		else
			tab[i++] = nbr;
	}
	return (tab);
}

int			check_number(int *tab, int len)
{
	int		icurrent;
	int		icheck;

	icurrent = -1;
	while (++icurrent < len)
	{
		icheck = icurrent;
		while (++icheck < len)
		{
			if (tab[icurrent] == tab[icheck])
				return (-1);
		}
	}
	return (0);
}

t_champ		*give_number(t_champ *champ, int len, int i)
{
	t_champ	*tmp;
	int		*tab;

	if (!(tab = (int *)malloc(sizeof(int) * len)))
		ft_exit(champ);
	tmp = champ;
	while (tmp)
	{
		tab[i++] = tmp->nbr;
		tmp = tmp->next;
	}
	tab = modif_tab(tab, len);
	i = 0;
	tmp = champ;
	while (tmp)
	{
		tmp->nbr = tab[i++];
		tmp = tmp->next;
	}
	i = check_number(tab, len);
	if (tab)
		free(tab);
	if (i == -1)
		ft_exit(champ);
	return (champ);
}
