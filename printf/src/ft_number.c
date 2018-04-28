/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:46:54 by acombe            #+#    #+#             */
/*   Updated: 2017/05/13 17:03:52 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_join	ft_begun(t_join tab, t_flags flag, char *s1, char *s2)
{
	if (flag.mode == 1 && flag.sp == 1 && flag.pl != 1 && s2[0] != '-')
		tab.p[tab.i++] = ' ';
	if (flag.mode == 5 || flag.mode == 13)
	{
		if (s2[0] == '-' && flag.pre > (int)ft_strlen(s2))
			flag.lc--;
		if (flag.mode == 5 && s2[0] == '-' && flag.pl == 1)
			flag.lc++;
		while ((tab.i + flag.pl - (int)ft_strlen(s1) < flag.lc - flag.pre &&
					flag.pre >= (int)ft_strlen(s2)) ||
				(tab.i + flag.pl - (int)ft_strlen(s1) <
					flag.lc - (int)ft_strlen(s2) &&
					(int)ft_strlen(s2) >= flag.pre))
			tab.p[tab.i++] = ' ';
		if (s2[0] == '0' && s2[1] == '\0')
			tab.p[tab.i++] = ' ';
	}
	return (tab);
}

t_join	ft_second(t_join tab, t_flags flag, char *s2)
{
	if (s2[0] == '0' && flag.di == 1 && (flag.pre != 0 ||
				(flag.mode != 9 && flag.mode != 13 &&
					flag.mode != 25 && flag.mode != 73 &&
					flag.mode != 77 && flag.mode != 89)))
	{
		if (s2[1] != '0')
			tab.p[tab.i++] = '0';
		if (s2[1] == 'x' || s2[1] == 'X')
			tab.p[tab.i++] = s2[1];
	}
	else if (s2[0] == '0' && flag.di == 1 && ft_isdigit(s2[1]))
		tab.p[tab.i++] = '0';
	else if (s2[0] == '0' && flag.di == 1 && s2[1] == '0')
		tab.p[tab.i++] = '0';
	if (s2[0] != '-' && flag.pl == 1)
		tab.p[tab.i++] = '+';
	return (tab);
}

t_join	ft_sixtynine(t_join tab, t_flags flag, char *s2, char *s1)
{
	if (flag.mode == 69)
	{
		flag.lc = flag.lc + (int)ft_strlen(s1);
		if (s2[0] == '0' && flag.di == 1)
		{
			flag.lc++;
			if (s2[1] == 'x' || s2[1] == 'X')
				flag.lc++;
		}
		if (flag.sp == 1)
			tab.p[tab.i++] = ' ';
		if (s2[0] == '-')
		{
			tab.p[tab.i++] = s2[tab.j++];
			flag.lc = flag.lc + 1;
		}
		while (tab.i < flag.lc - (int)ft_strlen(s2))
			tab.p[tab.i++] = '0';
	}
	return (tab);
}

t_join	ft_numbpre(t_flags flag, t_join tab, char *s2)
{
	if (flag.mode == 9 || flag.mode == 13 || flag.mode == 25 || flag.mode == 73)
	{
		tab.l = flag.pre - (int)ft_strlen(s2) + tab.i + tab.l;
		if (s2[0] == '-')
		{
			tab.l = tab.l + 2;
			tab.j++;
			tab.p[tab.i++] = '-';
		}
		if (flag.di == 1 && s2[0] == '0' && ft_isdigit(s2[1]) == 1)
			tab.l--;
		if (tab.l < 0)
			tab.l = 0;
		while (tab.i < tab.l)
			tab.p[tab.i++] = '0';
	}
	return (tab);
}

t_join	ft_number(t_flags flag, t_join tab, char *s1, char *s2)
{
	tab = ft_begun(tab, flag, s1, s2);
	tab = ft_second(tab, flag, s2);
	tab = ft_sixtynine(tab, flag, s2, s1);
	tab = ft_numbpre(flag, tab, s2);
	tab = ft_sevenseven(tab, flag, s1, s2);
	tab = ft_lastcpy(tab, flag, s2);
	return (tab);
}
