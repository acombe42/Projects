/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 18:25:38 by acombe            #+#    #+#             */
/*   Updated: 2017/05/09 18:25:53 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_init(t_flags flag, int *i)
{
	*i = 1;
	flag.pre = 0;
	flag.sp = 0;
	flag.pl = 0;
	flag.mode = 0;
	flag.lc = 0;
	flag.lon = 0;
	flag.i = 0;
	flag.j = 0;
	flag.save = (char*)malloc(sizeof(char) * 1);
	flag.save[0] = '\0';
	return (flag);
}

t_flags	ft_moins(char *str, int *i, t_flags flag)
{
	if (str[*i] == '-')
	{
		i[0]++;
		flag = ft_flag(flag, &str[*i]);
		while (str[*i] == ' ' || str[*i] == '+' ||
			str[*i] == '#' || str[*i] == '0')
			i[0]++;
		flag.lc = ft_atoi(&str[*i]);
		if (ft_isdigit(str[*i]) != 1)
			i[0]--;
		*i = *i + ft_strlen(ft_itoa(flag.lc));
		flag.mode = flag.mode + 16;
		if (flag.mode > 64)
			flag.mode = flag.mode - 64;
	}
	if (str[*i] == '.')
	{
		i[0]++;
		flag.pre = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]) == 1)
			i[0]++;
		if (str[*i] != '%')
			flag.mode = flag.mode + 8;
	}
	return (flag);
}

t_flags	ft_mode(char *str, int *i, t_flags flag)
{
	if (ft_isdigit(str[*i]))
	{
		while (str[*i] == '0')
			i[0]++;
		flag.lc = ft_atoi(&str[*i]);
		*i = *i + ft_strlen(ft_itoa(flag.lc));
		flag.mode = flag.mode + 4;
	}
	flag = ft_moins(str, i, flag);
	flag.h = 0;
	while (str[*i] == 'h')
	{
		flag.h++;
		i[0]++;
	}
	while (str[*i] == 'l' || str[*i] == 'j' || str[*i] == 'z')
	{
		i[0]++;
		flag.lon = 1;
	}
	return (flag);
}

t_flags	ft_pars(t_flags flag, va_list ap, char *str, char **string)
{
	int	i;

	i = 0;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
		flag = ft_did(flag, string, str, ap);
	if (str[i] == 'c' || str[i] == 'C')
		flag = ft_cc(flag, &str[i], ap, string);
	if (str[i] == 'x' || str[i] == 'X' || str[i] == 'o' || str[i] == 'O' ||
		str[i] == 'u' || str[i] == 'U' || str[i] == 'p')
		*string = ft_xoup(&str[i], &flag, *string, ap);
	if (str[i] == '%')
	{
		flag.mode = flag.mode + 2;
		flag.save = ft_unicode('%');
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	}
	return (flag);
}

int		ft_parsing(char *str, va_list ap, int *ret, char **string)
{
	int		i;
	t_flags flag;

	flag.pre = 0;
	flag = ft_init(flag, &i);
	flag = ft_flag(flag, &str[i]);
	while (str[i] == ' ' || str[i] == '+' || str[i] == '#' || str[i] == '0')
		i++;
	flag = ft_mode(str, &i, flag);
	flag.i = i;
	flag.j = *ret;
	flag = ft_pars(flag, ap, &str[i], string);
	*ret = flag.j;
	if (str[i] == 's' && flag.lon != 1)
		flag = ft_ss(flag, ap, string, ret);
	if (str[i] == 'S' || (str[i] == 's' && flag.lon == 1))
		flag = ft_sss(flag, ap, string, ret);
	if (flag.i != i)
		return (flag.i);
	if (flag.save[0] == '\0' && str[i] != 's' && str[i] != 'S')
		flag = ft_estzero(flag, &i, string, str);
	if (flag.save[0] != '\0' || str[i] == 's' || str[i] == 'S')
		i++;
	*ret = ft_strlen(*string);
	return (i);
}
