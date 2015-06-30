/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 20:41:23 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/03 15:28:31 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char *s)
{
	if (s)
	{
		while (*s)
			if (write(1, s++, 1) == -1)
				return ;
		if (write(1, "\n", 1))
			return ;
	}
}