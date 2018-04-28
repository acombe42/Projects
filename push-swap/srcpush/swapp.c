/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:14:54 by acombe            #+#    #+#             */
/*   Updated: 2017/06/07 15:48:54 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ra(t_all *val)
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
	write(1, "ra\n", 3);
}

void	rb(t_all *val)
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
	write(1, "rb\n", 3);
}

void	rr(t_all *val)
{
	ra(val);
	rb(val);
}
