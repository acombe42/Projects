/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:08:12 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 17:08:13 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

void	check_sa(t_all *val)
{
	int	i;

	i = val->taba[0];
	val->taba[0] = val->taba[1];
	val->taba[1] = i;
	val->coup++;
}

void	check_sb(t_all *val)
{
	int	i;

	i = val->tabb[0];
	val->tabb[0] = val->tabb[1];
	val->tabb[1] = i;
	val->coup++;
}

void	check_ss(t_all *val)
{
	check_sa(val);
	check_sb(val);
}

void	check_pa(t_all *val)
{
	int	i;
	int	save;

	i = 0;
	save = val->tabb[0];
	while (val->topb > i)
	{
		val->tabb[i] = val->tabb[i + 1];
		i++;
	}
	i = 0;
	val->topb--;
	val->topa++;
	while (i < val->topa)
		i++;
	while (i > 0)
	{
		val->taba[i] = val->taba[i - 1];
		i--;
	}
	val->taba[0] = save;
	val->coup++;
}

void	check_pb(t_all *val)
{
	int	i;
	int	save;

	i = 0;
	save = val->taba[0];
	while (i < val->topa)
	{
		val->taba[i] = val->taba[i + 1];
		i++;
	}
	i = 0;
	val->topa--;
	val->topb++;
	while (i < val->topb)
		i++;
	while (i > 0)
	{
		val->tabb[i] = val->tabb[i - 1];
		i--;
	}
	val->tabb[0] = save;
	val->coup++;
}
