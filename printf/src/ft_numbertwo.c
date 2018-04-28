/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbertwo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 17:17:55 by acombe            #+#    #+#             */
/*   Updated: 2017/05/13 17:18:50 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_join	ft_lastcpy(t_join tab, t_flags flag, char *s2)
{
	while (s2[tab.j])
	{
		if (flag.di == 1 && s2[0] == '0' && tab.j == tab.l)
		{
			tab.j++;
			if (s2[1] == 'x' || s2[1] == 'X')
				tab.j++;
		}
		if (tab.j == tab.l && s2[tab.j + 1] == '\0' && s2[tab.j] == '0' &&
			tab.i < flag.lc && flag.mode != 77 &&
			flag.mode != 69 && flag.mode != 17)
		{
			tab.j++;
			if (flag.lc > 0 && tab.i < flag.lc)
				tab.p[tab.i++] = ' ';
		}
		else if (s2[tab.j + 1] == '\0' && s2[tab.j] == '0' && flag.pre == 0 &&
			(tab.j == tab.l || (tab.j == tab.l + 1 && s2[tab.j - 1] == '0')) &&
			(flag.mode == 9 || flag.mode == 13 || flag.mode == 25 ||
					flag.mode == 73 || flag.mode == 77 || flag.mode == 89))
			tab.j++;
		else if (s2[tab.j])
			tab.p[tab.i++] = s2[tab.j++];
	}
	return (tab);
}

t_join	ft_sevenseven(t_join tab, t_flags flag, char *s1, char *s2)
{
	if (flag.mode == 77)
	{
		flag.lc = flag.lc + (int)ft_strlen(s1);
		while (((tab.i + flag.pl) < flag.lc - flag.pre &&
					flag.pre > (int)ft_strlen(s2)) ||
				((tab.i + flag.pl) < flag.lc - (int)ft_strlen(s2) &&
					(int)ft_strlen(s2) > flag.pre))
			tab.p[tab.i++] = ' ';
		tab.l = (int)flag.pre - (int)ft_strlen(s2) + tab.i + tab.l;
		if (s2[0] == '-')
		{
			tab.p[tab.i++] = '-';
			tab.l = tab.l + 2;
			tab.j++;
		}
		if (tab.l < 0)
			tab.l = 0;
		while (tab.i < tab.l)
			tab.p[tab.i++] = '0';
	}
	tab.l = tab.j;
	return (tab);
}
