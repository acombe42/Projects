/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:43:54 by acombe            #+#    #+#             */
/*   Updated: 2017/08/26 14:24:48 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_read(t_all *all)
{
	get_next_line(0, &all->str);
	if (ft_isnb(all->str) == 1 && nb_mot(all->str) == 1)
		all->nbant = ft_atoi(all->str);
	if (ft_isnb(all->str) == 1 && nb_mot(all->str) == 1)
		free(all->str);
	else if (all->str[0] == '#' && all->str[1] != '#')
	{
		parse(all);
		free(all->str);
		ft_read(all);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (all->nbant > 199999 || all->nbant < 0)
		write(2, "Error ! Trop de fourmis\n", 24);
	if (all->nbant > 199999 || all->nbant < 0)
		exit(0);
	while (get_next_line(0, &all->str) == 1)
	{
		parse(all);
		free(all->str);
	}
}

int		main(void)
{
	t_all	all;
	int		j;

	j = 0;
	ft_bzero(&all, sizeof(t_all));
	ft_read(&all);
	ft_putstr("\n");
	if (all.nbant == 0 || all.nbcmds == 0 || all.nbcmde == 0)
	{
		if (all.nbcmds == 0 || all.nbcmde == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	else
		ft_move(&all);
	return (0);
}
