/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:51:05 by acombe            #+#    #+#             */
/*   Updated: 2017/08/26 13:29:03 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	pondere(t_all *all)
{
	int	j;
	int	k;
	int	n;

	n = 0;
	k = 0;
	j = all->nbroom - 1;
	all->pond[all->fin] = 1;
	while (j > -1)
	{
		if (all->links[all->fin][j] == 1)
			all->pond[j] = 2;
		j--;
	}
	j = all->nbroom - 1;
	while (all->pond[all->stt] == 0)
		pond(all, &j, &k, &n);
	j = 0;
	while (j < all->nbroom)
		j++;
}

void	chemin(t_all *all)
{
	int	j;
	int	i;

	i = 0;
	all->chemin[0] = all->stt;
	while (all->chemin[i] != all->fin)
	{
		j = 0;
		while ((all->links[all->chemin[i]][j] != 1 ||
					all->pond[all->chemin[i]] - 1 != all->pond[j]) &&
			j < all->nbroom)
			j++;
		if (j == all->nbroom)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
		all->chemin[i] = j;
	}
	i = 0;
}

int		next(t_all *all, int j)
{
	int	i;
	int k;

	k = j;
	i = 0;
	while (all->ant[j] != all->chemin[i])
		i++;
	i++;
	while (k > -1)
	{
		if (all->ant[k] == all->chemin[i] && all->chemin[i] != all->fin)
			return (all->ant[j]);
		k--;
	}
	return (all->chemin[i]);
}

void	bouge(t_all *all)
{
	int	i;
	int	j;

	while (all->ant[all->nbant - 1] != all->fin)
	{
		i = 0;
		while (i < all->nbant)
		{
			while (all->ant[i] == all->fin)
				i++;
			j = all->ant[i];
			all->ant[i] = next(all, i);
			if (j != all->ant[i])
			{
				ft_putchar('L');
				ft_putnbr(i + 1);
				ft_putchar('-');
				ft_putstr(all->room[all->ant[i]]);
				ft_putchar(' ');
			}
			i++;
		}
		ft_putchar('\n');
	}
}

void	ft_move(t_all *all)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	pondere(all);
	chemin(all);
	while (i < all->nbant)
		all->ant[i++] = all->stt;
	bouge(all);
}
