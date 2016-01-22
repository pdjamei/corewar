/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 18:01:43 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 18:14:08 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assembleur.h>
#include <op.h>
#include <stdlib.h>
#define I (*i)

extern t_op	g_op_tab[17];

int			get_label_size(char *instr)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, instr))
			return (g_op_tab[i].label_size);
	}
	return (0);
}

int			get_has_pcode(char *instr)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, instr))
			return (g_op_tab[i].has_pcode);
	}
	return (0);
}

char		*get_next_token(char *line, int *i)
{
	char	*tok_str;
	int		j;

	if (line[I] == '\0' || line[I] == COMMENT_CHAR)
		return (NULL);
	if (!(tok_str = (char *)malloc(sizeof(char) * 1024)))
		return (NULL);
	ft_bzero(tok_str, 1024);
	j = 0;
	while (line[I] != '\0')
	{
		if (line[I] == COMMENT_CHAR)
			return (NULL);
		else if (is_ok_char(line[I]))
			tok_str[j++] = line[I];
		else if (tok_str[0] != '\0')
			break ;
		else if (line[I] == ';')
			return (NULL);
		I++;
	}
	return (tok_str);
}

int			get_true_addr(t_token *t_curr, t_sym last, int l_s)
{
	int		ret;

	ret = 0;
	if (t_curr)
	{
		ret = t_curr->addr;
		if (t_curr->type == label)
		{
			if (last == indirect)
				ret += 2;
			else if (last == reg)
				ret++;
		}
		else if (last == direct || last == direct_label)
		{
			if (l_s == 4)
				ret += 4;
			else
				ret += 2;
		}
	}
	return (ret);
}

int			get_prog_size(t_line *lst)
{
	t_line	*l_curr;
	t_token	*t_curr;
	int		l_s;
	t_sym	last;

	l_s = 0;
	l_curr = lst;
	t_curr = NULL;
	last = blank;
	while (l_curr)
	{
		t_curr = l_curr->line;
		while (t_curr && t_curr->next)
		{
			if (t_curr->type == instruction)
				l_s = get_label_size(t_curr->tok_str);
			t_curr = t_curr->next;
		}
		if (t_curr->type != label)
			last = t_curr->type;
		l_curr = l_curr->next;
	}
	return (get_true_addr(t_curr, last, l_s));
}
