/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:31:10 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 22:30:14 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <libft.h>
#include <op.h>
#include <assembleur.h>

#define COM COMMENT_CMD_STRING

extern t_op		g_op_tab[17];

t_header		*fill_name_or_comment(t_header *header, int fd)
{
	char		*text;
	char		*l;

	l = NULL;
	text = NULL;
	while (get_next_line(fd, &l))
	{
		if (!ft_strncmp(l, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		{
			if (!(text = get_text(l, 0)))
				return (ft_strdel(&l));
			ft_strcpy(header->prog_name, text);
			break ;
		}
		else if (!ft_strncmp(l, COM, ft_strlen(COM)))
		{
			if (!(text = get_text(l, 1)))
				return (ft_strdel(&l));
			ft_strcpy(header->comment, text);
			break ;
		}
		ft_strdel(&l);
	}
	ft_strdel(&text);
	return (header);
}

t_header		*fill_header(int fd)
{
	t_header	*header;

	if (!(header = (t_header *)malloc(sizeof(*header))))
		return (NULL);
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	if (!(header = fill_name_or_comment(header, fd)))
		return (NULL);
	if (!(header = fill_name_or_comment(header, fd)))
		return (NULL);
	return (header);
}

int				assembleur(char *name)
{
	int			fd;
	t_header	*header;

	if ((fd = open(name, O_RDONLY)) < 0)
		return (-1);
	if (!(header = fill_header(fd)))
		return (write(1, "Name or comment too long\n", 25));
	return (parse_file(fd, in_to_out(name), header));
}

int				main(int ac, char **av)
{
	if (ac == 2)
	{
		if (assembleur(av[1]) < -1)
			return (write(1, "File not found or bad rights\n", 29));
	}
	else
		return (write(1, "Bad arguments\n", 14));
	return (0);
}
