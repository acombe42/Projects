/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinxfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:44:33 by acombe            #+#    #+#             */
/*   Updated: 2017/05/08 19:32:41 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_join	ft_initialisation(t_join tab)
{
	tab.i = 0;
	tab.j = 0;
	tab.l = 0;
	(tab.p = (char*)malloc(sizeof(char) * tab.k + 1000));
	return (tab);
}

t_join	ft_beg(t_join tab, t_flags flag, char *s1, char *s2)
{
	if (flag.pl == 1 && s2[0] == '-')
		flag.pl = 0;
	if (flag.di == 1 && s2[0] == '0' && flag.pre != 0)
	{
		tab.l = 1;
		if (s2[1] == 'x' || s2[1] == 'X')
			tab.l = 2;
	}
	tab.k = 0;
	while (s1[tab.i] != '\0')
	{
		tab.p[tab.i] = s1[tab.i];
		tab.i++;
	}
	return (tab);
}

char	*ft_strjoinxfree(char *s1, char *s2, t_flags flag, int mode)
{
	t_join	tab;

	tab.k = ft_strlen(s1) + ft_strlen(s2);
	tab = ft_initialisation(tab);
	tab = ft_beg(tab, flag, s1, s2);
	if (mode % 2 == 0)
		tab = ft_carac(tab, flag, s2, s1);
	if (mode % 2 == 1)
		tab = ft_number(flag, tab, s1, s2);
	if (mode == 25 || mode == 26 || mode == 17 ||
		mode == 18 || mode == 56 || mode == 48)
	{
		while (tab.i < flag.lc + (int)ft_strlen(s1))
			tab.p[tab.i++] = ' ';
	}
	if (mode == 89 || mode == 90 || mode == 81 ||
		mode == 120 || mode == 132 || mode == 82)
	{
		while (tab.i < flag.lc)
			tab.p[tab.i++] = '0';
	}
	tab.p[tab.i] = '\0';
	return (tab.p);
}
