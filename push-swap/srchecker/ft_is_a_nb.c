/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:55:11 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 18:01:44 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

int		is_here(char *str, t_all *var, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (ft_atoi(str) == var->taba[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_a_nb(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 13)
		return (0);
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	return (1);
}

void	libero(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
	}
	if (tab)
		free(tab);
}

void	numbers(t_all *val, char **argv, int *j, int *i)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(argv[1], ' ');
	while (tab[*i] && *i < 502)
	{
		if (ft_is_a_nb(tab[*i]) == 0 || is_here(tab[*i], val, *i) == 0)
			*j = 1;
		val->taba[*i] = ft_atoi(tab[*i]);
		*i = *i + 1;
	}
	libero(tab);
}

void	takenumbers(t_all *val, int argc, char **argv, int *j)
{
	int		i;

	i = 0;
	if (argc == 2)
		numbers(val, argv, j, &i);
	else
	{
		while (i < argc - 1 && i < 502)
		{
			if (ft_is_a_nb(argv[i + 1]) == 0 ||
					is_here(argv[i + 1], val, i) == 0)
				*j = 1;
			val->taba[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	if (i > 500)
		*j = 2;
	val->topa = i;
	val->top = val->topa;
}
