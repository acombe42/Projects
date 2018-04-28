/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:10:33 by acombe            #+#    #+#             */
/*   Updated: 2017/08/16 16:39:12 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		find_room(t_all *all, char *r)
{
	int	i;
	int	save;

	i = 0;
	save = 0;
	while (save < all->nbroom)
	{
		while (r[i] == all->room[save][i] && r[i] != '\0')
			i++;
		if (all->room[save][i] == '\0' && r[i] == '\0')
			return (save);
		else
		{
			i = 0;
			save++;
		}
	}
	return (-1);
}

int		linkit(t_all *all, char **r1, char **r2)
{
	int	i;
	int	j;

	i = find_room(all, *r1);
	j = find_room(all, *r2);
	all->ld = 1;
	if (i == -1 || j == -1)
		return (0);
	all->links[i][j] = 1;
	all->links[j][i] = 1;
	i = 0;
	j = 0;
	while (*r1[i])
		*r1[i++] = '\0';
	i = 0;
	while (*r2[i])
		*r2[i++] = '\0';
	free(*r1);
	free(*r2);
	return (1);
}
