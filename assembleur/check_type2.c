/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 17:58:06 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 18:21:23 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <assembleur.h>

extern t_op	g_op_tab[17];

int			is_label_chars(char c)
{
	int		i;

	i = -1;
	while (LABEL_CHARS[++i])
	{
		if (c == LABEL_CHARS[i])
			return (1);
	}
	return (0);
}

int			is_ok_char(char c)
{
	if (!c)
		return (0);
	if (is_label_chars(c) || c == DIRECT_CHAR || c == LABEL_CHAR || c == '-')
		return (1);
	return (0);
}

int			is_instruction(char *str)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (!ft_strcmp(g_op_tab[i].name, str))
			return (1);
		i++;
	}
	return (0);
}

t_sym		get_token_type(char *tok_str)
{
	if (is_label(tok_str))
		return (label);
	if (is_instruction(tok_str))
		return (instruction);
	if (is_register(tok_str))
		return (reg);
	if (is_direct_label(tok_str))
		return (direct_label);
	if (is_direct(tok_str))
		return (direct);
	if (is_indirect(tok_str))
		return (indirect);
	return (blank);
}
