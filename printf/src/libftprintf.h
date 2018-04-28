/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:42:05 by acombe            #+#    #+#             */
/*   Updated: 2017/05/13 14:48:43 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

typedef struct	s_join
{
	int			i;
	int			j;
	int			l;
	size_t		k;
	char		*p;
}				t_join;

typedef struct	s_print
{
	va_list		ap;
	int			ret;
	int			save;
}				t_print;

typedef struct	s_wchar
{
	wchar_t		f;
	wchar_t		g;
	wchar_t		d;
	wchar_t		e;
}				t_wchar;

typedef	struct	s_flags
{
	int			pre;
	int			comp;
	int			lc;
	int			mode;
	int			di;
	int			pl;
	int			i;
	int			j;
	int			lon;
	int			h;
	int			sp;
	char		*save;
}				t_flags;

int				ft_parsing(char *str, va_list ap, int *ret, char **string);
char			*ft_hhitoa(int nb);
t_flags			ft_estzero(t_flags flag, int *i, char **string, char *str);
t_join			ft_carac(t_join tab, t_flags flag, char *s2, char *s1);
t_join			ft_number(t_flags flag, t_join tab, char *s2, char *s1);
t_join			ft_lastcpy(t_join tab, t_flags flag, char *s2);
t_join			ft_sevenseven(t_join tab, t_flags flag, char *s1, char *s2);
char			*ft_hitoa(int nb);
char			*ft_itoa(int nb);
char			*ft_litoa(long long nb);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strunicode(wint_t *wint);
char			*ft_toupper(char *c);
char			*ft_unicode(wchar_t c);
char			*ft_itoa_base_x(unsigned int nb, unsigned int base);
char			*ft_itoa_base_lx(unsigned long long int nb, unsigned int base);
char			*ft_itoa_base_hx(unsigned short int nb, unsigned int base);
char			*ft_itoa_base_hhx(unsigned char nb, unsigned int base);
int				ft_isdigit(int c);
int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd);
int				ft_putchar(int c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int nb);
void			ft_putstr_fd(char const *s, int fd);
int				ft_putstr(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strjoinxfree(char *s1, char *s2, t_flags flag, int mode);
int				ft_atoi(const char *str);
t_flags			ft_flag(t_flags flag, const char *str);
t_flags			ft_precision(const char *str, t_flags flag);
t_flags			ft_cc(t_flags flag, char *str, va_list ap, char **string);
t_flags			ft_did(t_flags flag, char **string, char *str, va_list ap);
t_flags			ft_sss(t_flags flag, va_list ap, char **string, int *ret);
t_flags			ft_ss(t_flags flag, va_list ap, char **string, int *ret);
char			*ft_xoup(char *str, t_flags *flag, char *string, va_list ap);

#endif
