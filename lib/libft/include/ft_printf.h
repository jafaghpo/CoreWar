/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:06:12 by iburel            #+#    #+#             */
/*   Updated: 2017/04/24 14:04:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <wchar.h>
# include <stdlib.h>
# include <stdarg.h>
# include "define.h"

# define FLAGS flags->flags
# define TYPE flags->type
# define FD flags->fd
# define PREC opt[0]
# define ADDORSPACE opt[1]
# define BLANKS opt[2]
# define HASHTAG opt[3]
# define SUB opt[3]
# define ZERO opt[4]

# define BLK "\x1B[30m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RES "\x1B[0m"

typedef struct s_flags	t_flags;
typedef struct s_pars	t_pars;

struct	s_pars
{
	t_uint	u;
	void	(*f)(t_flags *, t_uint, char **str, va_list ap);
};

struct	s_flags
{
	int		blanks;
	int		prec;
	int		fd;
	t_uint	type;
	t_uint	flags;
};

int		ft_printf(char *str, ...);
void	ft_flags(char **str, t_flags *flags, va_list ap);
int		ft_per(char **str, t_flags *flags, va_list ap);
void	ft_fillflags(t_flags *flags, t_uint u, char **str, va_list ap);
void	ft_type(t_flags *flags, t_uint u, char **str, va_list ap);
void	ft_blanks(t_flags *flags, t_uint u, char **str, va_list ap);
void	ft_precs(t_flags *flags, t_uint u, char **str, va_list ap);
void	ft_getutype(t_uint type, t_ullint *nbr);
void	ft_typeuint(t_ullint *nbr);
void	ft_typeuh(t_ullint *nbr);
void	ft_typeuhh(t_ullint *nbr);
void	ft_typeuj(t_ullint *nbr);
void	ft_typeuz(t_ullint *nbr);
void	ft_typeul(t_ullint *nbr);
void	ft_typeull(t_ullint *nbr);
void	ft_getstype(t_uint type, t_llint *nbr);
void	ft_typesint(t_llint *nbr);
void	ft_typesh(t_llint *nbr);
void	ft_typeshh(t_llint *nbr);
void	ft_typesj(t_llint *nbr);
void	ft_typesz(t_llint *nbr);
void	ft_typesl(t_llint *nbr);
void	ft_typesll(t_llint *nbr);
int		ft_printf_a(t_flags *flags, va_list ap);
int		ft_printf_b(t_flags *flags, va_list ap);
int		ft_printf_c(t_flags *flags, va_list ap);
int		ft_printf_d(t_flags *flags, va_list ap);
int		ft_printf_e(t_flags *flags, va_list ap);
int		ft_printf_f(t_flags *flags, va_list ap);
int		ft_printf_g(t_flags *flags, va_list ap);
int		ft_printf_k(t_flags *flags, va_list ap);
int		ft_printf_o(t_flags *flags, va_list ap);
int		ft_printf_p(t_flags *flags, va_list ap);
int		ft_printf_s(t_flags *flags, va_list ap);
int		ft_printf_u(t_flags *flags, va_list ap);
int		ft_printf_x(t_flags *flags, va_list ap);
int		ft_printf_3(t_flags *flags, va_list ap);
int		ft_printf_2(t_flags *flags, va_list ap);
int		ft_printf_per(t_flags *flags, va_list ap);
int		ft_buf(int fd, void *str, int size);
int		ft_color(char **str, int fd);
int		ft_conv(char c, va_list ap, t_flags *flags);
int		ft_printf_ind(wchar_t c, t_flags *flags);
int		ft_printf_putchar_fd(wchar_t c, int fd);
int		ft_printf_le(t_ldouble nbr, t_flags *flags);
int		ft_printf_dtoa_e(double nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_le(t_ldouble nbr, t_flags *flags, char **str);
int		ft_printf_lf(t_ldouble nbr, t_flags *flags);
int		ft_printf_dtoa_f(double nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_lf(t_ldouble nbr, t_flags *flags, char **str);
int		ft_printf_lg(t_ldouble nbr, t_flags *flags);
int		ft_printf_g_e(double nbr, t_flags *flags);
int		ft_printf_lg_le(t_ldouble nbr, t_flags *flags);
int		ft_printf_dtoa_g_e(double nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_lg_le(t_ldouble nbr, t_flags *flags, char **str);
int		ft_printf_g_f(double nbr, t_flags *flags);
int		ft_printf_lg_lf(t_ldouble nbr, t_flags *flags);
int		ft_printf_dtoa_g_f(double nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_lg_lf(t_ldouble nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_ent(double nbr, char **str);
int		ft_printf_dtoa_lent(t_ldouble nbr, char **str);
int		ft_printf_la(t_ldouble nbr, t_flags *flags);
int		ft_printf_dtoa_a(double nbr, t_flags *flags, char **str);
int		ft_printf_dtoa_la(t_ldouble nbr, t_flags *flags, char **str);
int		ft_printf_ktoa(time_t k, char **str);
time_t	ft_getmonth(time_t *k, time_t bis);
void	ft_day(time_t d, char **str);
void	ft_month(time_t m, char *str);
int		ft_printf_itoa_a(int nbr, char *str);
int		ft_printf_ls(wchar_t *str, t_flags *flags);
int		ft_printf_itoa(t_llint nbr, char **str);
int		ft_printf_itoa_base(t_ullint nbr, int base, char **str, int maj);
char	*ft_printf_strnew(char c, int size, int fd);

#endif
