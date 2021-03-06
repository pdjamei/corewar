/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:34:11 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 14:32:12 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*src;
	char	*find;
	size_t	size;

	src = (char *)s1;
	find = (char *)s2;
	size = ft_strlen(find);
	if (size == 0)
		return (char *)(src);
	if (size > n)
		return ((char *)NULL);
	while (n-- >= size && *src)
	{
		if (ft_strncmp(src, find, size) == 0)
			return ((char *)src);
		src++;
	}
	return ((char *)NULL);
}
