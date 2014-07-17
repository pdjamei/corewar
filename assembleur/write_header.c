/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:18:12 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 19:37:27 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <unistd.h>
#include <fcntl.h>

int			write_header(t_header *header, char *out)
{
	int		n;
	int		fd;

	if ((fd = open(out, O_WRONLY | O_TRUNC | O_CREAT, 0644)) < 0)
		return (-1);
	n = switch_endian(header->magic);
	write(fd, &n, sizeof(unsigned int));
	write(fd, &(header->prog_name), PROG_NAME_LENGTH + 4);
	n = switch_endian(header->prog_size);
	write(fd, &n, sizeof(unsigned int));
	write(fd, &(header->comment), COMMENT_LENGTH + 4);
	return (fd);
}
