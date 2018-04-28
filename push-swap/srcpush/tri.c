/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:49:00 by acombe            #+#    #+#             */
/*   Updated: 2017/06/21 16:00:10 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		medx(t_all *val)
{
	int	i;
	int	j;

	i = -1;
	if (val->tabmed)
		free(val->tabmed);
	val->tabmed = (int*)malloc(sizeof(int) * val->topa + 1);
	while (++i < val->topa - val->count)
		val->tabmed[i] = val->taba[i];
	i = 0;
	while (i < val->topa - val->count - 1)
	{
		if (val->tabmed[i] < val->tabmed[i + 1])
			i++;
		else
		{
			j = val->tabmed[i];
			val->tabmed[i] = val->tabmed[i + 1];
			val->tabmed[i + 1] = j;
			i = 0;
		}
	}
	return (val->tabmed[(val->topa - val->count + 1) / 2]);
}

void	onlythree(t_all *val)
{
	int	i;
	int	j;

	i = 0;
	j = (val->topa + 1) / 2;
	val->medx[val->i] = medx(val);
	while (checka(val) != 1)
	{
		if (val->taba[i] < val->medx[val->i])
			pb(val);
		else
			ra(val);
	}
	if (val->topa > 3)
	{
		val->i++;
		onlythree(val);
	}
}

void	fiftyfifty(t_all *val)
{
	int	i;
	int	j;

	j = val->topa / 2;
	i = 0;
	while (checko(val) != 1)
	{
		if (val->taba[i] <= val->medall)
			pb(val);
		else
			ra(val);
	}
}

void	trithree(t_all *val)
{
	if (val->taba[0] < val->taba[1] && val->taba[1] < val->taba[2] &&
			val->taba[2] < val->taba[3])
		return ;
	if (val->taba[3] < val->taba[2] && val->topa > 3)
	{
		ra(val);
		ra(val);
		sa(val);
		rra(val);
		rra(val);
		trithree(val);
	}
	if (val->taba[0] > val->taba[1])
	{
		sa(val);
		trithree(val);
	}
	if (val->taba[1] > val->taba[2])
	{
		ra(val);
		sa(val);
		rra(val);
		trithree(val);
	}
}

void	tri(t_all *val)
{
	val->i = 10;
	val->top = val->topa;
	val->topb = 0;
	if (ft_true(val) == 1)
		return ;
	val->medx[9] = val->medall;
	if (val->top > 45)
	{
		fiftyfifty(val);
		onlythree(val);
		trithree(val);
		val->count = val->topa;
		while (val->topa < val->top / 2 - 1 && val->topb > 9)
		{
			val->count = val->topa;
			takemedx(val);
			takethreeorless(val);
			trithree(val);
			ft_true(val);
		}
		end(val);
	}
	else
		little(val);
}
