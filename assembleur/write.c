/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:16:44 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 19:45:45 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

extern t_op	g_op_tab[18];

void		write_instruction(t_token *t_curr, int fd, char coding_byte)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, t_curr->tok_str))
		{
			write(fd, &(g_op_tab[i].opcode), 1);
			if (g_op_tab[i].has_pcode)
				write(fd, &(coding_byte), 1);
		}
	}
}

void		write_direct(t_token *t_curr, int fd, int label_size)
{
	int		n;

	if (t_curr->type == direct)
		n = switch_endian(ft_atoi(t_curr->tok_str + 1));
	else
		n = switch_endian(t_curr->addr);
	if (label_size != 4)
	{
		n = n >> 16;
		write(fd, &n, 2);
	}
	else
		write(fd, &n, 4);
}

void		write_reg(t_token *t_curr, int fd)
{
	int		n;

	n = ft_atoi(t_curr->tok_str + 1);
	write(fd, &n, 1);
}

void		write_indirect(t_token *t_curr, int fd)
{
	int		n;

	n = switch_endian(ft_atoi(t_curr->tok_str));
	n = n >> 16;
	write(fd, &n, 2);
}

int			write_file(t_line *lst, char *out, t_header *header, int fd)
{
	int		label_size;

	fd = write_header(header, out);
	label_size = 0;
	while (lst)
	{
		while (lst->line)
		{
			if (lst->line->type == instruction)
			{
				label_size = get_label_size(lst->line->tok_str);
				write_instruction(lst->line, fd, lst->coding_byte);
			}
			else if (lst->line->type == direct\
					|| lst->line->type == direct_label)
				write_direct(lst->line, fd, label_size);
			else if (lst->line->type == reg)
				write_reg(lst->line, fd);
			else if (lst->line->type == indirect)
				write_indirect(lst->line, fd);
			lst->line = lst->line->next;
		}
		lst = lst->next;
	}
	return (1);
}
