/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 17:57:06 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 18:21:21 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <assembleur.h>

int			is_register(char *str)
{
	if (str[0] == 'r' && ft_isdigit(str[1]))
		return (1);
	return (0);
}

int			is_direct(char *str)
{
	if (str[0] == DIRECT_CHAR\
			&& (ft_isdigit(str[1])\
				|| (str[1] == '-' && ft_isdigit(str[2]))))
		return (1);
	return (0);
}

int			is_direct_label(char *str)
{
	if (str[0] == DIRECT_CHAR && str[1] == LABEL_CHAR)
		return (1);
	return (0);
}

int			is_indirect(char *str)
{
	if (ft_isdigit(str[0]) || (str[0] == '-' && ft_isdigit(str[1])))
		return (1);
	return (0);
}

int			is_label(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}
