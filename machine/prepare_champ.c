/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:02:05 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:38:20 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "machine.h"
#include "arena.h"
#include "libft.h"

t_champdata			*add_data(t_champdata *champdata, t_champ *champ)
{
	t_champdata		*new;

	if (!(new = new_datachamp(champ)))
		return (champdata);
	if (!champdata)
		return (new);
	new->next = champdata;
	new->prev = champdata->prev;
	champdata->prev->next = new;
	champdata->prev = new;
	return (champdata);
}

int					conv_init(unsigned char *args, int size)
{
	int				i;
	int				exp;
	int				result;

	i = 0;
	exp = size - 1;
	result = 0;
	while (exp >= 0)
		result = result + args[i++] * ft_power(256, exp--);
	return (result);
}

void				get_code(int fd, t_champdata *champdata)
{
	int				i;
	int				j;
	int				total;
	int				ret;
	unsigned char	buff[READ_SIZE];

	total = 0;
	i = 0;
	while ((ret = read(fd, buff, READ_SIZE)) > 0)
	{
		if ((total = total + ret) > MEM_SIZE)
			exit(-1);
		j = -1;
		while (++j < total)
			champdata->parsing->code_content[i + j] = buff[j];
		i = i + j + 1;
	}
	if (total != champdata->parsing->size)
		exit(-1);
}

void				get_content(t_champdata *champdata, t_champ *champ)
{
	int				fd;
	unsigned char	buff[READ_SIZE];

	fd = open(champ->file, O_RDONLY);
	if (read(fd, buff, READ_SIZE) < READ_SIZE)
		exit(-1);
	if ((champdata->parsing->magic = conv_init(buff, 4)) != COREWAR_EXEC_MAGIC)
		exit(-1);
	if (!(champdata->name = ft_strndup((const char *)(buff + CURSOR_NAME),
					PROG_NAME_LENGTH)))
		exit(-1);
	if ((champdata->parsing->size = conv_init(buff + CURSOR_SIZE, 8)) <= 0
			|| champdata->parsing->size >= MEM_SIZE)
		exit(-1);
	get_code(fd, champdata);
	close(fd);
}

t_champdata			*ready_champ_for_arena(t_champ *champ)
{
	t_champdata		*champdata;

	if (!(champdata = (t_champdata *)malloc(sizeof(t_champdata))))
		return (NULL);
	champdata->next = champdata;
	champdata->prev = champdata;
	champdata->pid = -1;
	while (champ)
	{
		champdata = add_data(champdata, champ);
		get_content(champdata->prev, champ);
		champ = champ->next;
	}
	return (champdata);
}
