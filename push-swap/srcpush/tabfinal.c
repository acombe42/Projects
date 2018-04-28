/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabfinal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:43:37 by acombe            #+#    #+#             */
/*   Updated: 2017/06/21 15:36:35 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	tabfinal(t_all *val)
{
	int	i;
	int	j;

	i = 0;
	if (val->tabfinal)
		free(val->tabfinal);
	val->tabfinal = (int*)malloc(sizeof(int) * val->topa + 1);
	while (i <= val->topa)
	{
		val->tabfinal[i] = val->taba[i];
		i++;
	}
	i = 0;
	while (i < val->topa)
	{
		if (val->tabfinal[i] > val->tabfinal[i + 1] && i != val->topa)
		{
			j = val->tabfinal[i];
			val->tabfinal[i] = val->tabfinal[i + 1];
			val->tabfinal[i + 1] = j;
			i = 0;
		}
		else
			i++;
	}
}
