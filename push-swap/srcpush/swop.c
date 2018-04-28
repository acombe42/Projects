/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:19:40 by acombe            #+#    #+#             */
/*   Updated: 2017/06/07 15:49:26 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rra(t_all *val)
{
	int		i;
	int		save;
	int		j;

	i = 0;
	while (i < val->topa)
		i++;
	i--;
	save = val->taba[i];
	j = i;
	while (i > 0)
	{
		val->taba[i] = val->taba[i - 1];
		i--;
	}
	val->taba[0] = save;
	val->coup++;
	write(1, "rra\n", 4);
}

void	rrb(t_all *val)
{
	int		i;
	int		save;
	int		j;

	i = 0;
	while (i < val->topb)
		i++;
	i--;
	save = val->tabb[i];
	j = i;
	while (i > 0)
	{
		val->tabb[i] = val->tabb[i - 1];
		i--;
	}
	val->tabb[0] = save;
	val->coup++;
	write(1, "rrb\n", 4);
}

void	rrr(t_all *val)
{
	rra(val);
	rrb(val);
}
