/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:46:35 by acombe            #+#    #+#             */
/*   Updated: 2017/05/13 16:56:17 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_join	ft_strpre(t_join tab, t_flags flag, char *s2)
{
	if (flag.mode == 44 || flag.mode == 14)
	{
		if (flag.pre < (int)ft_strlen(s2))
		{
			while ((int)tab.k < flag.lc - flag.pre)
			{
				tab.p[tab.i++] = ' ';
				tab.k++;
			}
		}
		else
		{
			while ((int)tab.k < flag.lc - (int)ft_strlen(s2))
			{
				tab.p[tab.i++] = ' ';
				tab.k++;
			}
		}
	}
	return (tab);
}

t_join	ft_strlc(t_join tab, t_flags flag, char *s2)
{
	if (flag.mode == 6 || flag.mode == 36)
	{
		while ((int)tab.k < flag.lc - (int)ft_strlen(s2) &&
				flag.lc - (int)ft_strlen(s2) > 0)
		{
			tab.p[tab.i++] = ' ';
			tab.k++;
		}
		if (s2[0] == 0 && flag.mode == 6)
		{
			tab.i--;
			tab.p[tab.i++] = '\0';
		}
	}
	return (tab);
}

t_join	ft_strelse(t_join tab, t_flags flag, char *s1, char *s2)
{
	if (flag.mode == 78 || flag.mode == 70 ||
		flag.mode == 100 || flag.mode == 108)
	{
		flag.lc = flag.lc + (int)ft_strlen(s1);
		while (tab.i < flag.lc - flag.pre - (int)ft_strlen(s2) &&
				flag.lc - flag.pre - (int)ft_strlen(s2) > 0)
		{
			tab.p[tab.i++] = '0';
			tab.k++;
		}
	}
	if (flag.mode == 10 || flag.mode == 14 || flag.mode == 26 ||
			flag.mode == 40 || flag.mode == 44 || flag.mode == 56)
	{
		while (s2[tab.j] != '\0' && tab.j < flag.pre)
			tab.p[tab.i++] = s2[tab.j++];
	}
	return (tab);
}

t_join	ft_carac(t_join tab, t_flags flag, char *s2, char *s1)
{
	tab = ft_strlc(tab, flag, s2);
	tab = ft_strpre(tab, flag, s2);
	tab = ft_strelse(tab, flag, s1, s2);
	if (flag.mode != 10 && flag.mode != 14 &&
		flag.mode != 40 && flag.mode != 44)
	{
		while (s2[tab.j] && flag.mode != 26 && flag.mode != 56 &&
				flag.mode != 90 && flag.mode != 120)
			tab.p[tab.i++] = s2[tab.j++];
		if (flag.mode == 26 || flag.mode == 56)
		{
			while (tab.i < (int)flag.pre && tab.i < (int)flag.lc)
				tab.p[tab.i++] = ' ';
		}
		if (flag.mode == 90 || flag.mode == 120)
		{
			while (tab.i < flag.pre && tab.i < flag.lc)
				tab.p[tab.i++] = '0';
		}
		tab.p[tab.i] = '\0';
	}
	return (tab);
}
