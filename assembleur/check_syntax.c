/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:10:29 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 22:33:12 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <libft.h>
#include <unistd.h>

extern t_op	g_op_tab[17];

int			check_syntax(t_line *lst)
{
	t_line	*l_curr;
	t_token	*t_curr;
	int		ret;

	l_curr = lst;
	while (l_curr)
	{
		t_curr = l_curr->line;
		if (t_curr && t_curr->tok_str)
		{
			if (t_curr->type == label)
			{
				if ((ret = check_label(t_curr, l_curr)) < 0)
					return (ret);
				else if (ret == 1)
					l_curr = l_curr->next;
			}
			else if (t_curr->type == instruction)
				if (check_instruction(t_curr) < 0)
					return (-1);
		}
		l_curr = l_curr->next;
	}
	return (1);
}

int			check_label(t_token *t_curr, t_line *l_curr)
{
	if (!t_curr->next)
	{
		l_curr = l_curr->next;
		if (!l_curr || !l_curr->line || l_curr->line->type != instruction)
			return (-1);
		return (1);
	}
	else if (t_curr->next->type != instruction)
		return (-1);
	return (2);
}

int			check_instruction(t_token *t_curr)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, t_curr->tok_str))
			return (check_arg(t_curr->next, g_op_tab[i]));
		i++;
	}
	return (-1);
}

int			check_arg(t_token *t_curr, t_op op)
{
	t_sym	args_types[4];
	int		nb_args;

	nb_args = 0;
	while (t_curr)
	{
		if (t_curr->type == reg || t_curr->type == direct\
				|| t_curr->type == direct_label || t_curr->type == indirect)
		{
			args_types[nb_args++] = t_curr->type;
			if (nb_args > op.nb_params)
				return (-1);
		}
		t_curr = t_curr->next;
	}
	nb_args = 0;
	while (nb_args < op.nb_params)
	{
		if (args_types[nb_args] == direct_label)
			args_types[nb_args] = T_DIR;
		if (!(args_types[nb_args] & op.param_types[nb_args]))
			return (-1);
		nb_args++;
	}
	return (1);
}
