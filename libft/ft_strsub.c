/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 17:34:27 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 15:44:54 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libft.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*save_ret;
	char	*save;
	size_t	size;

	if (!s)
		return (NULL);
	save = (char *)s;
	size = ft_strlen((char *)s);
	if (start < 1 && len < 1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size - len));
	if (ret == NULL)
		return (NULL);
	save_ret = ret;
	while (start-- && *save)
		save++;
	while (len-- && *save)
	{
		*ret = *save;
		ret++;
		save++;
	}
	*ret = '\0';
	return (save_ret);
}
