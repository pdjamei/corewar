/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_negative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 19:32:14 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:33:04 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft.h"

int		negative_convert_int(unsigned char *args, int size)
{
	int	i;
	int	exp;
	int	result;

	i = 0;
	exp = size - 1;
	result = 0;
	while (exp >= 0)
		result += (255 - args[i++]) * ft_power(256, exp--);
	return ((result + 1) * -1);
}

int		negative_convert_int_instruction(unsigned char *args, int size,
											unsigned char *arena)
{
	int				i;
	int				exp;
	int				result;
	unsigned char	*tmp;

	i = 0;
	exp = size - 1;
	result = 0;
	while (exp >= 0)
	{
		tmp = new_adress(args + i++, arena);
		result += (255 - tmp[0]) * ft_power(256, exp--);
	}
	return ((result + 1) * -1);
}
