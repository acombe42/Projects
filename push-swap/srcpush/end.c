/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 15:03:39 by acombe            #+#    #+#             */
/*   Updated: 2017/06/13 15:59:30 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		check(t_all *val)
{
	int	i;

	i = 0;
	while (i < val->topb)
	{
		if (val->tabb[i] > val->medx[val->i])
			return (1);
		else
			i++;
	}
	return (0);
}

int		checker(t_all *val)
{
	int	i;

	i = 0;
	while (i < val->topb)
	{
		if (val->tabb[0] >= val->tabb[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int		littlecheck(t_all *val)
{
	int	save;
	int	i;

	i = 0;
	save = val->taba[i];
	val->j = 0;
	while (i < val->topa)
	{
		if (save > val->taba[i])
			save = val->taba[i];
		i++;
	}
	while (save != val->taba[val->j])
		val->j++;
	if (val->j > val->topa / 2)
		return (2);
	if (val->j == 0)
		return (1);
	return (0);
}

void	little(t_all *val)
{
	val->count = 0;
	if (val->topa == 3)
	{
		forthree(val);
		return ;
	}
	while (val->topa > 2)
	{
		if (littlecheck(val) == 1)
			pb(val);
		else if (littlecheck(val) == 0)
			ra(val);
		else if (littlecheck(val) == 2)
			rra(val);
	}
	if (val->topa == 2 && val->taba[0] > val->taba[1])
		sa(val);
	while (val->topb != 0)
		pa(val);
}

void	end(t_all *val)
{
	int	save;
	int	i;

	i = 0;
	if (val->top > 14)
	{
		takelastmed(val);
		takethreeorless(val);
		trithree(val);
		val->count = val->topa;
		ft_true(val);
	}
	save = val->i;
	while (val->count < val->top - 40 || ft_true(val) != 1)
	{
		lasttri(val);
		if (val->i < 0)
			break ;
	}
	finishhim(val);
}
