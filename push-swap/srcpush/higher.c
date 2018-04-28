/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   higher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:09:46 by acombe            #+#    #+#             */
/*   Updated: 2017/06/13 15:49:26 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		checka(t_all *val)
{
	int	i;

	i = 0;
	while (i < val->topa)
	{
		if (val->taba[i] < val->medx[val->i])
			return (0);
		i++;
	}
	return (1);
}

int		checko(t_all *val)
{
	int	i;

	i = 0;
	while (i < val->topa)
	{
		if (val->taba[i] < val->medall)
			return (0);
		i++;
	}
	return (1);
}

int		higher(t_all *val, int i)
{
	int	j;

	j = 0;
	while (j < val->topa)
	{
		if (val->taba[j] > i)
			return (0);
		j++;
	}
	return (1);
}

void	finishhim(t_all *val)
{
	while (val->topb != 0)
	{
		if (checker(val) == 1)
			pa(val);
		else
			rb(val);
		trithree(val);
	}
}
