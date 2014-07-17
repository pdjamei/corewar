/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 18:16:36 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 23:31:32 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft.h"

void	convert_dectbin(int nbr, char *args_type)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		args_type[i--] = nbr % 2;
		nbr = nbr / 2;
	}
}

void	stock_convert_nbr(unsigned char *tmp, unsigned char *arena,
								int value)
{
	int				i;
	int				value_cpy;
	unsigned char	tab[4];

	i = 4;
	value_cpy = value;
	while (--i >= 0)
	{
		tab[i] = (value_cpy >= 0 ? value % 256 : value);
		tab[i] = (tab[i] ? 255 + value % 256 + 1 : 255 + value % 256);
		value /= 256;
	}
	i = 0;
	while (i < 4)
	{
		tmp[0] = tab[i++];
		tmp = new_adress(tmp + 1, arena);
	}
}

int		convert_int_instruction(unsigned char *args, int size,
									unsigned char *arena)
{
	int				i;
	int				exp;
	int				result;
	unsigned char	*tmp;

	if (args[0] >= 128)
		return (negative_convert_int_instruction(args, size, arena));
	i = 0;
	exp = size - 1;
	result = 0;
	while (exp >= 0)
	{
		tmp = new_adress(args + i++, arena);
		result += tmp[0] * ft_power(256, exp--);
	}
	return (result);
}

int		convert_int(unsigned char *args, int size)
{
	int	i;
	int	exp;
	int	result;

	if (args[0] >= 128)
		return (negative_convert_int(args, size));
	i = 0;
	exp = size - 1;
	result = 0;
	while (exp >= 0)
		result += args[i++] * ft_power(256, exp--);
	return (result);
}
