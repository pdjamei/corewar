/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:15:41 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/03 15:28:18 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	char			*s12;
	char			*s22;

	if (s1 && s2)
	{
		s12 = (char *)s1;
		s22 = (char *)s2;
		while (n--)
		{
			c1 = *(unsigned char *)s12;
			c2 = *(unsigned char *)s22;
			if (c1 != c2)
				return (c1 - c2);
			s12 = s12 + 1;
			s22 = s12 + 1;
		}
		return (0);
	}
	return (-1);
}
