/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:41:06 by acombe            #+#    #+#             */
/*   Updated: 2017/08/16 16:41:16 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		comment(t_all *all)
{
	int	i;

	i = 0;
	while (all->str[i + 1])
	{
		all->comment[all->j][i] = all->str[i + 1];
		i++;
	}
	return (2);
}

int		command(t_all *all)
{
	if (all->str[2] == 's' && all->str[3] == 't' && all->str[4] == 'a' &&
			all->str[5] == 'r' && all->str[6] == 't' && all->str[7] == '\0')
	{
		all->nbcmds++;
		start(all);
	}
	else if (all->str[2] == 'e' && all->str[3] == 'n' && all->str[4] == 'd' &&
			all->str[5] == '\0')
	{
		all->nbcmde++;
		end(all);
	}
	return (2);
}

int		room(t_all *all)
{
	int	i;

	i = 0;
	if (all->str[i] == 'L')
		return (0);
	while (all->str[i] != ' ')
	{
		all->room[all->nbroom][i] = all->str[i];
		i++;
	}
	all->room[all->nbroom][i] = '\0';
	i++;
	if (ft_isnb(&all->str[i]) == 0)
		return (0);
	all->coord_x[all->nbroom] = ft_atoi(all->str);
	while (all->str[i] != ' ' && all->str[i])
		i++;
	i++;
	if (ft_isnb(&all->str[i]) == 0)
		return (0);
	all->coord_y[all->nbroom] = ft_atoi(all->str);
	all->nbroom++;
	return (1);
}

int		ft_link(t_all *all)
{
	char	*room1;
	char	*room2;
	int		i;

	i = 0;
	if ((!(room1 = (char*)malloc(sizeof(char) * 1000))) ||
		(!(room2 = (char*)malloc(sizeof(char) * 1000))))
		return (0);
	while (all->str[i] != '-' && all->str[i])
	{
		room1[i] = all->str[i];
		i++;
	}
	room1[i++] = '\0';
	while (all->str[i] != '\0')
	{
		room2[i - ft_strlen(room1) - 1] = all->str[i];
		i++;
	}
	room2[i - ft_strlen(room1) - 1] = '\0';
	if (check(room1, room2, all) == 0)
		return (0);
	if (linkit(all, &room1, &room2) == 0)
		return (0);
	return (1);
}

void	parse(t_all *all)
{
	int	i;

	i = 0;
	if (all->str[0] == '\0')
		return ;
	if (all->str[0] == '#' && all->str[1] != '#')
	{
		i = comment(all);
		all->j++;
	}
	else if (all->str[0] == '#' && all->str[1] == '#' && all->ld == 0)
		i = command(all);
	else if (nb_mot(all->str) == 3 && all->ld == 0)
		i = room(all);
	else if (nb_mot(all->str) == 1)
		i = ft_link(all);
	if (i == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	if (i != 2)
		write(1, all->str, ft_strlen(all->str));
	if (i != 2)
		write(1, "\n", 1);
}
