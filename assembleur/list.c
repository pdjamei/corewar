/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:55:11 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 15:09:47 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <op.h>
#include <stdlib.h>

t_token			*create_token(t_sym type, char *str)
{
	t_token		*new;

	if (!(new = (t_token *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	new->tok_str = str;
	return (new);
}

t_token			*add_token(t_token *list, t_sym type, char *str)
{
	t_token		*new;
	t_token		*current;

	new = create_token(type, str);
	if (!list)
		return (new);
	current = list;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
	return (list);
}

t_line			*line_add(t_line *lst, t_token *line)
{
	t_line		*new;
	t_line		*current;

	if (!(new = (t_line *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->line = line;
	new->coding_byte = 0;
	if (!lst)
		return (new);
	current = lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
	return (lst);
}
