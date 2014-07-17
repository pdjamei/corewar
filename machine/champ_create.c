/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:57:16 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:38:47 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "machine.h"
#include "libft.h"
#include "arena.h"

t_champdata			*new_datachamp(t_champ *champ)
{
	t_champdata		*new;
	
	if (!(new = (t_champdata *)malloc(sizeof(t_champdata))))
		return (NULL);
	new->father = 0;
	new->pid = champ->nbr;
	new->carry = 0;
	new->PC = 0;
	ft_bzero(new->reg, REG_NUMBER * sizeof(unsigned int));
	new->reg[0] = champ->nbr;
	new->cycle = 0;
	new->cycle_to_die = 0;
	new->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	new->parsing = (t_parse *)malloc(sizeof(t_parse));
	new->parsing->code_content = (char *)malloc(MEM_SIZE);
	if (!new->cmd || !new->parsing->code_content)
		return (NULL);
	new->cmd->type_args[0] = 0;
	new->cmd->type_args[1] = 0;
	new->cmd->type_args[2] = 0;
	new->next = new;
	new->prev = new;
	return (new);
}

int			ft_ischamp(char *s)
{
	int		len;

	if (access(s, F_OK) == 0 && access(s, R_OK) == 0)
	{
		len = ft_strlen(s);
		if ((len - 4) >= 0 && s[len - 4] == '.'
				&& s[len - 3] == 'c' && s[len - 2] == 'o' && s[len - 1])
			return (1);
	}
	return (0);
}

t_champ		*new_champ(char *s, int n)
{
	t_champ	*champ;

	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		return (NULL);
	champ->nbr = n;
	champ->file = ft_strdup(s);
	champ->next = NULL;
	champ->prev = NULL;
	return (champ);
}

t_champ		*add_champ(t_champ *champ, char *s, int n)
{
	t_champ	*tmp;

	if (champ == NULL)
		return (new_champ(s, n));
	tmp = champ;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_champ(s, n);
	tmp->next->prev = tmp;
	return (champ);
}

t_champ		*champ_list(t_champ *champ, char **av, int ac, int nbr_champ)
{
	int		i;
	int		number;

	number = -1;
	i = -1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-n") == 0)
		{
			if (av[++i] && number == -1 && ft_isnbr(av[i]) == 1)
				number = ft_atoi(av[i]);
			else
				ft_exit(champ);
		}
		else if (ft_ischamp(av[i]) == 1 && ++nbr_champ)
		{
			champ = add_champ(champ, av[i], number);
			number = -1;
		}
		else
			ft_exit(champ);
	}
	if (number != -1)
		ft_exit(champ);
	return (give_number(champ, nbr_champ, 0));
}
