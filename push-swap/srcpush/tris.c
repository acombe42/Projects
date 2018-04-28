/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:29:30 by acombe            #+#    #+#             */
/*   Updated: 2017/06/21 15:39:34 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	takemedx(t_all *val)
{
	int	i;

	i = 0;
	val->i--;
	i = 0;
	while (val->tabb[i] >= val->medx[val->i] && val->topb > 9)
		pa(val);
	if (val->count == val->topa && val->i > 1)
		takemedx(val);
}

void	takethreeorless(t_all *val)
{
	int	i;
	int	j;

	j = (val->topa - val->count + 1) / 2;
	i = 0;
	if (val->topa - val->count <= 3)
		return ;
	val->i++;
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
		while (higher(val, val->taba[val->topa - 1]) == 0)
			rra(val);
		val->i++;
		takethreeorless(val);
	}
}

void	trilesscount(t_all *val)
{
	if (val->taba[0] < val->taba[1] && val->taba[1] < val->taba[2])
		return ;
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

int		medy(t_all *val)
{
	int	j;
	int	i;

	i = -1;
	if (val->tabmed)
		free(val->tabmed);
	val->tabmed = (int*)malloc(sizeof(int) * (val->topb + 100));
	while (++i < val->topb)
		val->tabmed[i] = val->tabb[i];
	i = 0;
	while (i < val->topb - 1)
	{
		if (val->tabmed[i] <= val->tabmed[i + 1])
			i++;
		else
		{
			j = val->tabmed[i];
			val->tabmed[i] = val->tabmed[i + 1];
			val->tabmed[i + 1] = j;
			i = 0;
		}
	}
	return (val->tabmed[(val->topb + 1) / 2]);
}

void	takelastmed(t_all *val)
{
	int	i;
	int j;

	i = 0;
	val->i--;
	j = val->topb / 2;
	if (val->tabmed)
	{
		free(val->tabmed);
		val->tabmed = NULL;
	}
	val->medx[val->i] = medy(val);
	while (check(val) == 1)
	{
		if (val->tabb[i] > val->medx[val->i] && val->topb > 0)
			pa(val);
		else
			rb(val);
	}
}
