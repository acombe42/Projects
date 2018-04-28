/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:32:44 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 18:52:25 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_true(t_all *val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < val->topa - 1)
	{
		if (val->taba[i] < val->taba[i + 1])
			i++;
		else
		{
			i++;
			j++;
		}
	}
	if (j == 0)
		return (1);
	return (0);
}

void	lasttri(t_all *val)
{
	int i;

	i = 0;
	if (val->medx[val->i - 1] != 0 && val->i > -1)
		takemedx(val);
	else if (val->medx[val->i - 1] == 0 && val->count < val->top - 40)
		takelastmed(val);
	takethreeorless(val);
	trithree(val);
	while (ft_true(val) != 1 && val->top % 2 != 0)
	{
		pb(val);
		trithree(val);
	}
	val->count = val->topa;
}

void	liber(t_all *val)
{
	if (val->taba)
		free(val->taba);
	if (val->taba)
		free(val->tabb);
	if (val->taba)
		free(val->tabfinal);
	if (val->tabmed)
		free(val->tabmed);
}

int		main(int argc, char **argv)
{
	int		i;
	t_all	val;

	ft_bzero(&val, sizeof(t_all));
	i = 0;
	if (!(val.taba = (int*)malloc(sizeof(int) * 2000)))
		return (0);
	if (!(val.tabb = (int*)malloc(sizeof(int) * 2000)))
		return (0);
	takenumbers(&val, argc, argv, &i);
	if (i != 0)
	{
		write(2, "Error\n", 6);
		if (i == 2)
			write(2, "Trop de nombre, mechant !\n", 26);
		liber(&val);
		return (0);
	}
	tabfinal(&val);
	val.medall = val.tabfinal[val.topa / 2];
	tri(&val);
	liber(&val);
	write(1, "\0", 1);
	return (0);
}
