/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:10:13 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/06 13:24:01 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct			s_for
{
	char				*opt;
	size_t				min;
	size_t				pre;
	char				len;
	char				type;
	int					zero;
}						t_for;

typedef union			u_val
{
	int					d;
	char				hhd;
	short				hd;
	long				ld;
	long long			lld;
	intmax_t			jd;
	ssize_t				zd;
	unsigned int		u;
	unsigned char		hhu;
	unsigned short		hu;
	unsigned long		lu;
	unsigned long long	llu;
	uintmax_t			ju;
	size_t				zu;
	char				c;
	char				*s;
	wint_t				lc;
	wchar_t				*ls;
	void				*p;
}						t_val;

typedef struct			s_var
{
	t_val				*u;
	t_for				*f;
	char				*pre;
	char				*mid;
	char				*str;
	char				*suf;
}						t_var;

const char				*end_op(const char *s);
t_var					*ft_parse_opt(const char *s, t_var *x);
t_var					*ft_parse(const char *s, t_var *x);
char					ft_next_conversion(const char *str);
int						ft_printf(const char *format, ...);
int						is_opt(char c);
t_var					*ft_init(const char *format);
void					ft_assign(t_var *x, va_list ap);
t_var					*ft_insert(t_var *x);
char					*ft_itoa_base(unsigned long long n, char *base);
t_var					*ft_conv_d(t_var *x);
t_var					*ft_conv_s(t_var *x);
t_var					*ft_conv_c(t_var *x);
t_var					*ft_conv_d_aux_bis(t_var *x);
t_var					*ft_conv_d_aux(t_var *x, char *str);
void					change_pre(t_var *x, char *str);
void					change_str(t_var *x, char *str);
void					change_mid(t_var *x, char *str);
void					change_suf(t_var *x, char *str);
void					ft_free_all(t_var *x);
int						ft_is_null_u(t_var *x);
char					*ft_strndup(const char *s, size_t n);
char					*ft_insert_plus(char *str);
void					ft_putwchar_t(wchar_t w);
int						ft_count_bits(unsigned int n);
void					ft_putstr_uni(wchar_t *s);
void					ft_print_c(t_var *x);
void					ft_print_s(t_var *x);
t_var					*ft_insert_str(t_var *x);
void					ft_final_print(char *s1, char *s2, char *s3, char *s4);
size_t					ft_ret_c(t_var *x);
size_t					ft_ret_s(t_var *x);
char					*ft_insert_minus(char *str);

#endif
