/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 17:41:50 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 19:30:21 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char			*in_to_out(char *name)
{
	int		len;
	char	*new;

	len = ft_strlen(name);
	if (!(new = (char *)malloc(sizeof(char) * (len + 3))))
		return (NULL);
	ft_strcpy(new, name);
	ft_strcpy(new + len - 2, ".cor\0");
	return (new);
}

void			close_fd(int *fd)
{
	if (fd[0])
		close(fd[0]);
	if (fd[1])
		close(fd[1]);
}

char			*get_text(char *line, char flag)
{
	char		*text;
	int			decal;

	decal = 0;
	while (line[decal] && line[decal] != '\"')
		decal++;
	text = ft_strdup(line + decal + 1);
	text[ft_strlen(text) - 1] = '\0';
	if (flag && ft_strlen(text) > COMMENT_LENGTH)
		return (ft_strdel(&text));
	else if (!flag && ft_strlen(text) > PROG_NAME_LENGTH)
		return (ft_strdel(&text));
	return (text);
}
