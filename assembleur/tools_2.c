/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:15:57 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 17:09:23 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <assembleur.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>

void		update_pos(t_token *t_curr, int *pos, int *l_s)
{
	if (t_curr->type == instruction)
	{
		(*pos)++;
		(*l_s) = get_label_size(t_curr->tok_str);
		if (get_has_pcode(t_curr->tok_str))
			(*pos)++;
	}
	else if (t_curr->type == direct || t_curr->type == direct_label)
		(*pos) = (*pos) + (*l_s);
	else if (t_curr->type == reg)
		(*pos)++;
	else if (t_curr->type == indirect)
		(*pos) = (*pos) + 2;
}

void		update_addr(t_line **line)
{
	int		pos;
	int		l_s;
	t_token	*t_curr;
	t_line	*l_curr;

	pos = 0;
	l_s = 0;
	l_curr = *line;
	while (l_curr)
	{
		t_curr = l_curr->line;
		while (t_curr)
		{
			t_curr->addr = pos;
			update_pos(t_curr, &pos, &l_s);
			t_curr = t_curr->next;
		}
		l_curr = l_curr->next;
	}
}

void		do_coding_byte(t_line **lst, int i)
{
	t_token	*t_curr;
	t_line	*l_curr;

	l_curr = *lst;
	while ((i = 0) || l_curr)
	{
		t_curr = l_curr->line;
		while (t_curr)
		{
			if (t_curr->type == direct || t_curr->type == direct_label)
				l_curr->coding_byte = (l_curr->coding_byte + 2) << 2;
			else if (t_curr->type == indirect)
				l_curr->coding_byte = (l_curr->coding_byte + 3) << 2;
			else if (t_curr->type == reg)
				l_curr->coding_byte = (l_curr->coding_byte + 1) << 2;
			if (t_curr->type == label)
				t_curr->tok_str[ft_strlen(t_curr->tok_str) - 1] = '\0';
			else
				i++;
			t_curr = t_curr->next;
		}
		while (i++ < 4)
			l_curr->coding_byte = l_curr->coding_byte << 2;
		l_curr = l_curr->next;
	}
}

int			switch_endian(int num)
{
	int		swapped;

	swapped = ((num >> 24) & 0xFF) | ((num << 8) & 0xFF0000)\
				| ((num >> 8) & 0xFF00) | ((num << 24) & 0xFF000000);
	return (swapped);
}

int			do_label(t_line **line)
{
	t_line	*l_curr;
	t_token	*t_curr;
	int		addr;

	l_curr = *line;
	while (l_curr)
	{
		t_curr = l_curr->line;
		while (t_curr)
		{
			if (t_curr->type == direct_label)
			{
				if ((addr = get_label_addr(t_curr->tok_str + 2, *line)) == -1)
					return (-1);
				t_curr->addr = addr - get_inst_addr(t_curr);
			}
			t_curr = t_curr->next;
		}
		l_curr = l_curr->next;
	}
	return (1);
}
