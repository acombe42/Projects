/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swapp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:08:01 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 17:08:02 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

void	check_ra(t_all *val)
{
	int	save;
	int	i;

	i = 0;
	save = val->taba[0];
	while (i < val->topa)
	{
		val->taba[i] = val->taba[i + 1];
		i++;
	}
	val->taba[i - 1] = save;
	val->coup++;
}

void	check_rb(t_all *val)
{
	int	save;
	int	i;

	i = 0;
	save = val->tabb[0];
	while (i < val->topb)
	{
		val->tabb[i] = val->tabb[i + 1];
		i++;
	}
	val->tabb[i - 1] = save;
	val->coup++;
}

void	check_rr(t_all *val)
{
	check_ra(val);
	check_rb(val);
}
