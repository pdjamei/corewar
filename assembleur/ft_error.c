/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 15:12:35 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 15:12:37 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembleur.h>
#include <libft.h>

int			ft_error(char *s, t_line **f_list, int ret)
{
	ft_putendl(s);
	free_f_list(f_list);
	return (ret);
}
