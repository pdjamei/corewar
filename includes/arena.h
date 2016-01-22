/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdjamei <pdjamei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 14:28:19 by pdjamei           #+#    #+#             */
/*   Updated: 2014/06/18 15:54:32 by pdjamei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "op.h"
# include "machine.h"

# define READ_SIZE		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define CURSOR_MAGIC	(0)
# define CURSOR_NAME	(CURSOR_MAGIC + 4)
# define CURSOR_SIZE	(CURSOR_NAME + PROG_NAME_LENGTH)
# define CURSOR_COMMENT	(CURSOR_SIZE + 8)

# define ABS(x)			(((x) < 0) ? (-x) : (x))

typedef struct			s_cycle
{
	int					nbr_live;
	int					cycle_to_die;
	int					current_cycle;
}						t_cycle;

typedef struct			s_cmd
{
	int					funct;
	int					type_args[3];
	unsigned char		args[(IND_SIZE + REG_SIZE + DIR_SIZE) * 4];
}						t_cmd;

typedef struct			s_parse
{
	int					magic;
	int					size;
	char				*code_content;
}						t_parse;

typedef struct			s_champd
{
	unsigned int		father;
	unsigned int		pid;
	int					carry;
	char				*name;
	char				*comment;
	unsigned char		*pc;
	unsigned int		reg[REG_NUMBER];
	int					cycle;
	int					cycle_to_die;
	t_cmd				*cmd;
	t_parse				*parsing;
	struct s_champd		*next;
	struct s_champd		*prev;
}						t_champd;

typedef struct			s_tab
{
	int					cycles;
	void				(*function)(unsigned char *, t_champd *);
}						t_tab;

extern t_tab			g_funct_tab[16];
int						g_pid;
int						g_winner_id;
char					*g_winner_name;

int						spec_func(t_champd*tmp, unsigned char *arena);

void					convert_dectbin(int c, char *args_type);

void					instruct(t_champd *tmp, unsigned char *arena);
unsigned char			*new_adress(unsigned char *pc, unsigned char *arena);

void					remove_level(t_champd *champ, t_champd *tmp);

void					live(unsigned char *arena, t_champd *champ);
void					load(unsigned char *arena, t_champd *champ);
void					store(unsigned char *arena, t_champd *champ);
void					add(unsigned char *arena, t_champd *champ);
void					sub(unsigned char *arena, t_champd *champ);
void					and(unsigned char *arena, t_champd *champ);
void					or(unsigned char *arena, t_champd *champ);
void					xor(unsigned char *arena, t_champd *champ);
void					jump(unsigned char *arena, t_champd *champ);
void					load_index(unsigned char *arena, t_champd *champ);
void					store_index(unsigned char *arena, t_champd *champ);
void					fork_corewar(unsigned char *arena, t_champd *champ);
void					long_load(unsigned char *arena, t_champd *champ);
void					long_load_index(unsigned char *arena,
						t_champd *champ);
void					long_fork(unsigned char *arena, t_champd *champ);
void					aff(unsigned char *arena, t_champd *champ);

int						check_round(t_champd *champ, t_cycle *cycle);
t_champd				*ready_champ_for_arena(t_champ *champ);
void					charge_param(t_champd *champdata,
						unsigned char *arena);
void					launch_battle(int nbr_cycle, unsigned char *arena,
								t_champd *champdata, t_cycle *cycle);

int						negative_convert_int_instruction(unsigned char *args,
						int size, unsigned char *arena);
int						negative_convert_int(unsigned char *args, int size);

int						gimme_reg_nbr(int reg);
int						gimme_param_value(t_champd *champ, t_cmd *cmd,
						int arg, unsigned char *arena);
void					add_elem(t_champd *root);
int						exec_live(t_champd *tmp, t_champd *champ);
void					stock_convert_nbr(unsigned char *tmp,
						unsigned char *arena, int value);
int						convert_int_instruction(unsigned char *args, int size,
									unsigned char *arena);
int						convert_int(unsigned char *args, int size);

void					ft_dump(unsigned char *arena, t_champd *champ,
						t_cycle *cycle);

t_champd				*new_datachamp(t_champ *champ);

#endif
