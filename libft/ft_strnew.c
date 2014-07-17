/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:37:11 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 14:32:08 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size > 0)
	{
		str = (char *)ft_memalloc((size + 1) * sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_memset(str, '\0', size + 1);
		return (str);
	}
	return (char *)(NULL);
}
