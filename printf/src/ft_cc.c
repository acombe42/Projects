/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:37:20 by acombe            #+#    #+#             */
/*   Updated: 2017/05/11 16:37:30 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_sss(t_flags flag, va_list ap, char **string, int *ret)
{
	wint_t *wint;

	flag.mode = flag.mode + 32;
	wint = (wint_t*)malloc(sizeof(wint_t) * 4000);
	wint = va_arg(ap, wint_t*);
	if (wint == NULL)
	{
		flag.save = "(null)";
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
		*ret = ft_strlen(*string);
		flag.i++;
	}
	if (wint != NULL)
		flag.save = ft_strunicode(wint);
	if (wint != NULL)
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	return (flag);
}

t_flags	ft_ss(t_flags flag, va_list ap, char **string, int *ret)
{
	flag.mode = flag.mode + 32;
	flag.save = (char*)malloc(sizeof(char) * 4000);
	flag.save = va_arg(ap, char*);
	if (flag.save == NULL)
	{
		flag.save = "(null)";
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
		*ret = ft_strlen(*string);
		flag.i++;
	}
	else
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	return (flag);
}

t_flags	ft_coc(t_flags flag, va_list ap, char **string)
{
	int	i;

	i = 0;
	flag.save = ft_unicode(va_arg(ap, wchar_t));
	if (flag.save[0] == 0)
	{
		flag.mode = flag.mode + 2;
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
		if (flag.lc != 0)
			flag.j = flag.j + flag.lc;
		else
			flag.j = flag.j + 1;
		flag.i++;
	}
	if (flag.save[0] != 0)
		flag.mode = flag.mode + 2;
	if (flag.save[0] != 0)
		*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	return (flag);
}

t_flags	ft_cc(t_flags flag, char *str, va_list ap, char **string)
{
	int	i;

	i = 0;
	if (str[i] == 'c' && flag.lon != 1)
	{
		flag.save = (char*)malloc(sizeof(char) * 30);
		flag.save[0] = (va_arg(ap, int));
		if (flag.save[0] == 0)
		{
			flag.mode = flag.mode + 2;
			*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
			if (flag.lc != 0)
				flag.j = flag.j + flag.lc - 1;
			flag.j = flag.j + 1;
			flag.i++;
		}
		else
		{
			flag.mode = flag.mode + 2;
			*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
		}
	}
	else
		flag = ft_coc(flag, ap, string);
	return (flag);
}

t_flags	ft_estzero(t_flags flag, int *i, char **string, char *str)
{
	flag.mode = flag.mode + 2;
	flag.save = (char*)malloc(sizeof(char) * 2);
	flag.save[0] = str[*i];
	flag.save[1] = '\0';
	*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	return (flag);
}
