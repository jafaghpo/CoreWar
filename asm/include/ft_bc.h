/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:10:12 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/01 16:24:27 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BC_H
# define FT_BC_H

# include "asm.h"

typedef enum e_flag		t_flag;
typedef enum e_next		t_next;
typedef enum e_type		t_type;
typedef struct s_stack	t_stack;
typedef struct s_heap	t_heap;
typedef struct s_token	t_token;
typedef struct s_label	t_label;

enum	e_flag
{
	inferior_op,
	closed_bracket,
	final
};

enum	e_next
{
	operand,
	operator
};

enum	e_type
{
	invalid,
	whitespace,
	number,
	label,
	bracket,
	low_op,
	high_op,
	delimiter
};

struct	s_stack
{
	t_stack	*next;
	int		token;
	t_type	rank;
};

struct	s_heap
{
	t_stack	*nb;
	t_stack	*op;
};

struct	s_token
{
	t_type	*type;
	t_next	next;
	int		cursor;
	int		bracket;
	int		sign;
	int		error;
	int		size;
};

int		ft_bc(char *expr, t_label *labels, int *error, int size);

int		lexer(char *expr, t_token *token, t_heap *stack, t_label *labels);

void	eval_number(char *expr, t_token *token, t_heap *stack);
void	eval_operator(char *expr, t_token *token, t_heap *stack);
void	eval_bracket(char *expr, t_token *token, t_heap *stack);
void	eval_invalid(char *expr, t_token *token);
void	eval_whitespace(void);

void	eval_stack(char *expr, t_token *token, t_heap *stack, t_flag flag);
void	reduce_op(char *expr, t_token *token, t_heap *s);
void	reduce_b(t_token *token, t_heap *s);
void	reduce_s(t_token *token, t_heap *s);

void	push_token(int current, t_token *token, t_stack **stack, t_type rank);
int		pop_token(t_token *token, t_stack **stack);

int		add_calc(int a, int b, int *error);
int		sub_calc(int a, int b, int *error);
int		mult_calc(int a, int b, int *error);
int		div_calc(int a, int b, int *error);
int		mod_calc(int a, int b, int *error);

int		and_calc(int a, int b, int *error);
int		or_calc(int a, int b, int *error);
int		xor_calc(int a, int b, int *error);
int		lshift_calc(int a, int b, int *error);
int		rshift_calc(int a, int b, int *error);

int		atoi_base(char *str, t_token *token);

#endif
