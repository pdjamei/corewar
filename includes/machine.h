/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:41:43 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/15 19:52:30 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct      s_champ
{
    char            *file;
    int             nbr;
    struct s_champ  *next;
    struct s_champ  *prev;
}                   t_champ;

void				ft_exit(t_champ *champ);

t_champ				*give_number(t_champ *champ, int len, int i);

void				launch_match(int nbr_cycles, t_champ *champ);

t_champ				*champ_list(t_champ *champ, char **av, int ac, int nbr);

int					ft_isnbr(char *s);

#endif
