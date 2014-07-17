/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:20:22 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/21 18:50:56 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		minus;
	int		res;

	res = 0;
	minus = 1;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'
				|| *str == '\r' || *str == '\f' || *str == '\v'))
			str++;
		if (*str == '-' && str++)
			minus = -1;
		else if (*str == '+' && str++)
			minus = 1;
		while (*str && *str >= '0' && *str <= '9')
			res = res * 10 + (*str++ - '0');
	}
	return (minus * res);
}
