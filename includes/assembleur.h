/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembleur.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 15:33:22 by mcassagn          #+#    #+#             */
/*   Updated: 2014/06/15 20:07:30 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLEUR_H
# define ASSEMBLEUR_H

# include <op.h>
# define HEAD_SIZE (10 + PROG_NAME_LENGTH + COMMENT_LENGTH)

typedef enum		e_sym
{
	reg = T_REG, direct = T_DIR, direct_label = T_DIR + 1,
	indirect = T_IND, instruction, label, newline, blank
}					t_sym;

typedef struct		s_token
{
	t_sym			type;
	char			*tok_str;
	int				addr;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct		s_line
{
	t_token			*line;
	char			coding_byte;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_op
{
	char			*name;
	int				nb_params;
	int				param_types[4];
	int				opcode;
	int				nb_cycles;
	char			*description;
	int				has_pcode;
	int				label_size;
	int				has_idx;
}					t_op;

int					parse_file(int fd_in, char *out, t_header *header);
t_token				*add_token(t_token *list, t_sym type, char *tok_str);
t_line				*line_add(t_line *lst, t_token *line);
char				*in_to_out(char *name);
int					*get_fd(char *name);
void				close_fd(int *fd);
char				*get_text(char *line, char flag);
char				*get_next_token(char *line, int *i);
void				update_addr(t_line **line);
int					get_label_addr(char *lab, t_line *line);
void				do_coding_byte(t_line **lst, int i);
int					get_prog_size(t_line *lst);
int					write_header(t_header *header, char *out);
int					write_file(t_line *lst, char *out,\
						t_header *header, int fd);
int					get_inst_addr(t_token *lst);
int					do_label(t_line **line);
int					check_arg(t_token *t_curr, t_op op);
int					check_instruction(t_token *t_curr);
int					check_label(t_token *t_curr, t_line *l_curr);
int					check_syntax(t_line *lst);
int					ft_error(char *s, t_line **f_list, int ret);
int					get_label_size(char *instr);
int					get_has_pcode(char *instr);
t_sym				get_token_type(char *tok_str);
int					is_register(char *str);
int					is_direct(char *str);
int					is_direct_label(char *str);
int					is_indirect(char *str);
int					is_label(char *str);
int					is_instruction(char *str);
int					is_ok_char(char c);
int					is_label_chars(char c);
void				update_pos(t_token *t_curr, int *pos, int *l_s);
void				free_f_list(t_line **f_list);
int					switch_endian(int num);

#endif
