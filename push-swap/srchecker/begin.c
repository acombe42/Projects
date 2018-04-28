/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:07:46 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 18:36:24 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

void	suite(char **tab, t_all *var, int i)
{
	if (tab[i][0] == 'r' && tab[i][1] == 'b' && tab[i][2] == '\0')
		check_rb(var);
	else if (tab[i][0] == 'r' && tab[i][1] == 'r' && tab[i][2] == '\0')
		check_rr(var);
	else if (tab[i][0] == 'r' && tab[i][1] == 'r'
		&& tab[i][2] == 'b' && tab[i][3] == '\0')
		check_rrb(var);
	else if (tab[i][0] == 'r' && tab[i][1] == 'r'
		&& tab[i][2] == 'a' && tab[i][3] == '\0')
		check_rra(var);
	else if (tab[i][0] == 'r' && tab[i][1] == 'r'
		&& tab[i][2] == 'r' && tab[i][3] == '\0')
		check_rrr(var);
}

int		if_ok(char *str)
{
	if (str[0] != 'p' && str[0] != 'r' && str[0] != 's')
		return (0);
	if (str[0] == 'p')
	{
		if ((str[1] != 'a' && str[1] != 'b') || str[2] != '\0')
			return (0);
	}
	if (str[0] == 'r')
	{
		if ((str[1] != 'a' && str[1] != 'b' && str[2] != '\0'
			&& str[1] == 'r' && str[2] != '\0' && str[2] != 'a' &&
				str[2] != 'b' && str[2] != 'r') || (str[3] != '\0'))
			return (0);
		if ((str[1] != 'r' && str[1] != 'a' && str[1] != 'b') ||
			(str[1] != 'r' && str[2] != '\0'))
			return (0);
	}
	if (str[0] == 's')
	{
		if ((str[1] != 'a' && str[1] != 'b' && str[1] != 's') || str[2] != '\0')
			return (0);
	}
	return (1);
}

int		ft_tru(t_all *val)
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

void	begin(t_all *var, int *i, char ***etapes)
{
	*i = 0;
	*etapes = NULL;
	if (!(var->taba = (int*)malloc(sizeof(int) * 501)))
		return ;
	if (!(var->tabb = (int*)malloc(sizeof(int) * 501)))
		return ;
}
