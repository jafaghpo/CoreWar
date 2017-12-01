/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:31:33 by niragne           #+#    #+#             */
/*   Updated: 2017/12/01 19:19:52 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libft.h"
# include "libmat.h"
# include "display.h"

# define ERROR_INVALID_ARGUMENT	"error: invalid argument"
# define ERROR_OPEN_COR			"error: couldn't open .cor"
# define ERROR_CHAMP_TOO_BIG	"error: champion is too big"
# define ERROR_CHAMP_FILE		"error: couldn't parse .cor file"
# define ERROR_DUPLICATE_POS	"error: duplicate player numbers"
# define ERROR_TOO_MANY_PLAYERS	"error: too many players"
# define ERROR_MAGIC_NUMBER		"error: wrong magic number"
# define ERROR_CHAMP_SIZE		"error: wrong champion size"
# define ERROR_CHAMP_POS		"error: wrong pos"

# define LIST_FLAGS				"v"
# define LIST_ARGS				"dn"

# define READ_MAX				CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 16
# define HEADER_SIZE			PROG_NAME_LENGTH + COMMENT_LENGTH + 16

typedef struct s_player		t_player;
typedef struct s_args		t_args;
typedef struct s_file		t_file;
typedef struct s_proc		t_proc;
typedef struct s_inst		t_inst;
typedef struct s_champ		t_champ;

typedef char				t_int8;
typedef short int			t_int16;
typedef int					t_int32;
typedef long int			t_int64;
typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;

struct		s_player
{
	t_uint32	size;
	char		*name;
	char		*comment;
	t_uint8		*buffer;
};

struct		s_proc
{
	t_uint32	pc;
	t_uint32	carry : 1;
	t_uint32	reg[REG_NUMBER];
	t_uint32	player;
	t_uint32	live;
	t_uint32	id;
	t_proc		*next;
};

struct		s_args
{
	t_uint8	dump : 1;
	t_uint8	visu : 1;
	int		dumps;
	int		nb_players;
};

struct		s_file
{
	char	*name;
	int		pos;
	t_file	*next;
};

struct		s_inst
{
	t_uint8	size;
	t_uint8	type;
	t_int32	value;
	t_int32	real;
};

struct		s_champ
{
	char		*name;
	t_uint32	id;
	t_uint32	number;
	t_uint32	live;
};

extern t_op		op_tab[17];
extern t_uint32	g_id;
extern t_champ	g_champs[4];

t_uint16	get_uint16(t_uint32 pc);
t_uint32	get_uint32(t_uint8 *data);
t_uint32    get_uint32_mem(t_uint32 pc);
t_player	*get_players(t_file *files, int nb_players);
void		load_players(t_player *players, int nb_players);
void		flags_v(t_args *flags);
t_file		*parse_flags(t_args *flags, char **av, int ac);
void		init_proc(t_proc **cycle, int nb);
t_file		*add_file(t_args *flags, t_file *files, char *name, int *pos);
int			get_dumps(t_args *flags, char *str);
int			get_nums(t_args *flags, char *str);
void		get_name(char *file);
void    	fill_pos_players(t_file *files, int nb_players);
void   		*vm(void *av);
void 		insert_proc(t_proc **cycle, t_proc *proc, t_uint32 pos);
void		remove_proc(t_proc *proc);
t_int32     get_args(t_uint32 pc, t_inst *args, t_uint8 op);
int			check_type(int op, t_inst *type);
t_int32		get_ind(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal);
t_int32		get_reg(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal);
t_int32		get_dir(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal);
t_int32		get_void(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal);
void   		live(t_int32 value, t_int32 player);
void   		put_uint32(t_uint32 x, t_uint32 i);
t_proc      *create_proc(t_proc *p, t_int32 pc, t_int32 nb_cycle);
t_int32    	get_real_value(t_inst *args, t_proc *p, t_uint8 mod);
t_int32 	ft_abs(t_int32 x);
t_uint8  	check_reg(t_inst *args);
void 		proc_foreach(t_proc **cycle, t_uint32 nb_cycle);
void    	exec_proc(t_proc **cycle, t_uint32 nb_cycle, t_proc *tmp);
t_int32    get_player_id(t_uint32 octet);

/*
** debug
*/
void		debug_print_file(t_file *files);
void		debug_flags(t_args *flags);
void		debug_players(t_player *players, int nb_players);
void		debug_map(void);
void		debug_proc(t_proc *proc);
void		debug_cycle(t_proc **cycle);
void		debug_inst(t_inst *args, int pc, int op);

/*
** op
*/
void 		op_live(t_proc *p, t_inst *args, t_uint32 nb_cycle);
void 		op_ld(t_proc *p, t_inst *args);
void 		op_st(t_proc *p, t_inst *args);
void 		op_add(t_proc *p, t_inst *args);
void 		op_sub(t_proc *p, t_inst *args);
void 		op_and(t_proc *p, t_inst *args);
void 		op_or(t_proc *p, t_inst *args);
void 		op_xor(t_proc *p, t_inst *args);
void 		op_zjmp(t_proc *p, t_inst *args);
void 		op_ldi(t_proc *p, t_inst *args);
void 		op_sti(t_proc *p, t_inst *args);
void 		op_fork(t_proc *p, t_inst *args, t_int32 nb_cycle, t_proc **procs);
void 		op_lld(t_proc *p, t_inst *args);
void 		op_lldi(t_proc *p, t_inst *args);
void 		op_lfork(t_proc *p, t_inst *args, t_int32 nb_cycle, t_proc **procs);
void 		op_aff(t_proc *p, t_inst *args);

/*
** vm
*/

#endif
