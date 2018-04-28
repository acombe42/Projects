/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 16:54:49 by acombe            #+#    #+#             */
/*   Updated: 2017/08/17 16:55:49 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	pond(t_all *all, int *j, int *k, int *n)
{
	if (all->pond[*j] == 0)
	{
		while (*k < all->nbroom && all->pond[*j] == 0)
		{
			if (all->links[*j][*k] == 1 && all->pond[*k] != 0)
			{
				all->pond[*j] = all->pond[*k] + 1;
				*n = 0;
			}
			*k = *k + 1;
		}
		*k = 0;
	}
	if (*j == 0 && *n == 0)
	{
		*n = 1;
		*j = all->nbroom;
	}
	if (*n == 1 && *j == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	*j = *j - 1;
}
