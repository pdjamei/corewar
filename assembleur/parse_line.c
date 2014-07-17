/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:51:36 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 22:31:14 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <assembleur.h>
#include <stdlib.h>
#include <libft.h>
#include <unistd.h>

extern t_op	g_op_tab[17];

int			update_list(t_line **f_list, t_header *header)
{
	int		ret;

	if ((ret = check_syntax(*f_list)) < 0)
		return (ft_error("Parse error", f_list, ret));
	do_coding_byte(f_list, 0);
	update_addr(f_list);
	header->prog_size = get_prog_size(*f_list);
	if (do_label(f_list) < 0)
		return (ft_error("Label error", f_list, -3));
	return (1);
}

int			parse_file(int fd, char *out, t_header *header)
{
	int		i;
	char	*tok_str;
	t_token	*list;
	t_line	*f_list;
	char	*line;

	line = NULL;
	f_list = NULL;
	while (get_next_line(fd, &line) && !(i = 0))
	{
		list = NULL;
		if (line[i] != COMMENT_CHAR)
			while (line[i] != '\0' && (tok_str = get_next_token(line, &i)))
				list = add_token(list, get_token_type(tok_str), tok_str);
		if (list)
			f_list = line_add(f_list, list);
		ft_strdel(&line);
	}
	if ((i = update_list(&f_list, header)) < 0)
		return (i);
	write_file(f_list, out, header, 0);
	return (ft_error("", &f_list, 0));
}
