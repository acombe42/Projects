/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:42:31 by acombe            #+#    #+#             */
/*   Updated: 2017/08/16 16:38:12 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		nb_mot(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
		j++;
	}
	return (j);
}

void	start(t_all *all)
{
	int i;

	i = 0;
	write(1, all->str, ft_strlen(all->str));
	write(1, "\n", 1);
	free(all->str);
	get_next_line(0, &all->str);
	while (all->str[i])
	{
		all->start[i] = all->str[i];
		i++;
	}
	all->stt = all->nbroom;
	parse(all);
}

void	end(t_all *all)
{
	int i;

	i = 0;
	write(1, all->str, ft_strlen(all->str));
	write(1, "\n", 1);
	free(all->str);
	get_next_line(0, &all->str);
	while (all->str[i])
	{
		all->end[i] = all->str[i];
		i++;
	}
	all->fin = all->nbroom;
	parse(all);
}

int		ft_isnb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		check(char *r1, char *r2, t_all *all)
{
	int	i;
	int j;

	j = all->nbroom - 1;
	while (j >= 0)
	{
		i = 0;
		while (r1[i] == all->room[j][i] && r1[i] != '\0')
			i++;
		if (r1[i] == '\0' && all->room[j][i] == '\0')
			break ;
		j--;
	}
	j = all->nbroom - 1;
	while (j >= 0)
	{
		i = 0;
		while (r2[i] == all->room[j][i] && r2[i] != '\0')
			i++;
		if (r2[i] == '\0' && all->room[j][i] == '\0')
			break ;
		j--;
	}
	j++;
	return (j);
}
