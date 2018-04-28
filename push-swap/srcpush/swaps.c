/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:58:09 by acombe            #+#    #+#             */
/*   Updated: 2017/06/21 16:11:39 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sa(t_all *val)
{
	int	i;

	i = val->taba[0];
	val->taba[0] = val->taba[1];
	val->taba[1] = i;
	val->coup++;
	write(1, "sa\n", 3);
}

void	sb(t_all *val)
{
	int	i;

	i = val->tabb[0];
	val->tabb[0] = val->tabb[1];
	val->tabb[1] = i;
	val->coup++;
	write(1, "sb\n", 3);
}

void	ss(t_all *val)
{
	sa(val);
	sb(val);
}

void	pa(t_all *val)
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
	write(1, "pa\n", 3);
}

void	pb(t_all *val)
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
	write(1, "pb\n", 3);
}
