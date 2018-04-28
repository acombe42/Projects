/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:19:52 by acombe            #+#    #+#             */
/*   Updated: 2017/05/08 19:23:14 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags		ft_precision(const char *str, t_flags flag)
{
	int	i;

	i = 0;
	flag.pre = 0;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]) == 1)
		{
			flag.pre = flag.pre + (str[i] - 48);
			if (ft_isdigit(str[i + 1] == 1))
				flag.pre = flag.pre * 10;
			i++;
		}
	}
	return (flag);
}

t_flags		ft_flag(t_flags flag, const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '+' || str[i] == '#' || str[i] == '0')
	{
		if (str[i] == ' ')
			flag.sp = 1;
		if (str[i] == '+')
			flag.pl = 1;
		if (str[i] == '#')
			flag.di = 1;
		if (str[i] == '0')
			flag.mode = 64;
		i++;
	}
	return (flag);
}

char		*ft_cop(const char *str, int *ret, char *string, int *i)
{
	if (str[*i] != '\0')
		string[*ret] = str[*i];
	if (str[*i] != '\0')
		*ret = *ret + 1;
	if (str[*i] != '\0')
		i[0]++;
	string[*ret] = '\0';
	return (string);
}

char		*ft_add_carac(const char *str, t_print *stc, char *string, int *i)
{
	int	j;

	j = 0;
	if (str[*i] == '%' && str[*i + 1] == '\0')
		*i = *i + 1;
	if (str[*i] == '%')
	{
		j = ft_parsing((char*)&str[*i], stc->ap, &stc->ret, &string);
		if (string[0] == '\0')
		{
			write(1, string, stc->ret);
			stc->save = stc->ret;
			stc->ret = 0;
		}
	}
	if (str[*i] == '%')
		*i = *i + j;
	return (string);
}

int			ft_printf(const char *str, ...)
{
	t_print	stc;
	int		i;
	int		j;
	char	*string;

	va_start(stc.ap, str);
	i = 0;
	j = 0;
	stc.save = 0;
	stc.ret = 0;
	string = (char*)malloc(sizeof(char) * 1000);
	while (str[i])
	{
		if (str[i] == '%')
			string = ft_add_carac(str, &stc, string, &i);
		else
			string = ft_cop(str, &stc.ret, string, &i);
	}
	string[stc.ret] = '\0';
	va_end(stc.ap);
	write(1, string, stc.ret);
	return (stc.ret + stc.save);
}
