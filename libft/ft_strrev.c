/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:08:53 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 14:32:19 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <string.h>

char		*ft_strrev(char *s)
{
	size_t		size;
	char		*ret;
	char		*save_ret;

	size = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	save_ret = ret;
	while (size--)
		*ret++ = *(s + size);
	return (save_ret);
}
