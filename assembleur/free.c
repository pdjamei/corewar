/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:12:28 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 18:22:41 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <stdlib.h>
#include <libft.h>

void		free_t_list(t_token **t_list)
{
	t_token	*t_curr;
	t_token	*temp;

	t_curr = *t_list;
	while (t_curr)
	{
		temp = t_curr;
		t_curr = t_curr->next;
		temp->type = 0;
		temp->addr = 0;
		ft_strdel(&(temp->tok_str));
		temp->next = NULL;
		temp->prev = NULL;
		free(temp);
		temp = NULL;
	}
}

void		free_f_list(t_line **f_list)
{
	t_line	*l_curr;
	t_line	*temp;

	l_curr = *f_list;
	while (l_curr)
	{
		temp = l_curr;
		l_curr = l_curr->next;
		free_t_list(&(temp->line));
		temp->coding_byte = 0;
		temp->next = NULL;
		temp->prev = NULL;
		free(temp);
		temp = NULL;
	}
}
