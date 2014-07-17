/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:12:43 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 16:20:25 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assembleur.h>
#include <op.h>
#include <stdlib.h>

int			get_label_addr(char *lab, t_line *line)
{
	t_token	*t_curr;
	t_line	*l_curr;
	size_t	lab_size;

	l_curr = line;
	lab_size = ft_strlen(lab);
	while (l_curr)
	{
		t_curr = l_curr->line;
		while (t_curr)
		{
			if (t_curr->type == label && lab_size == ft_strlen(t_curr->tok_str)\
					&& !ft_strcmp(lab, t_curr->tok_str))
				return (t_curr->addr);
			t_curr = t_curr->next;
		}
		l_curr = l_curr->next;
	}
	return (-1);
}

int			get_inst_addr(t_token *lst)
{
	t_token	*t_curr;

	t_curr = lst;
	while (t_curr)
	{
		if (t_curr->type == instruction)
			return (t_curr->addr);
		t_curr = t_curr->prev;
	}
	return (-1);
}
