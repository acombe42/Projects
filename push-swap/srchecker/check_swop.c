/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:24:21 by acombe            #+#    #+#             */
/*   Updated: 2017/06/06 17:24:23 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

void	check_rra(t_all *val)
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
}

void	check_rrb(t_all *val)
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
}

void	check_rrr(t_all *val)
{
	check_rra(val);
	check_rrb(val);
}
