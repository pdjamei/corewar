/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 23:35:55 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:36:01 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "machine.h"
#include "libft.h"

int			ft_isnbr(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		nbr_cycle;
	t_champ	*champ;

	champ = NULL;
	if (ac <= 1)
		ft_exit(champ);
	nbr_cycle = -1;
	if (ft_strcmp(av[1], "-dump") == 0 && ft_isnbr(av[2]) == 1)
	{
		nbr_cycle = ft_atoi(av[2]);
		champ = champ_list(champ, &(av[3]), ac - 3, 0);
	}
	else
		champ = champ_list(champ, &(av[1]), ac - 1, 0);
	launch_match(nbr_cycle, champ);
	return (0);
}
