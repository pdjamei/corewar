/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:17:59 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 15:35:33 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*s12;
	const char	*s22;

	if (s1 && s2)
	{
		s12 = s1;
		s22 = s2;
		while (n--)
		{
			*s12 = *s22;
			if ((unsigned char)c == *s12)
				return (void *)(++s12);
			s12++;
			s22++;
		}
	}
	return (NULL);
}
