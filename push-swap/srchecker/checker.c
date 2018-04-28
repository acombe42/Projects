/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:07:21 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 18:38:22 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcpush/push.h"

void	do_it(char **tab, t_all *var)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == 'p' && tab[i][1] == 'b' && tab[i][2] == '\0')
			check_pb(var);
		else if (tab[i][0] == 'p' && tab[i][1] == 'a' && tab[i][2] == '\0')
			check_pa(var);
		else if (tab[i][0] == 's' && tab[i][1] == 'a' && tab[i][2] == '\0')
			check_sa(var);
		else if (tab[i][0] == 's' && tab[i][1] == 'b' && tab[i][2] == '\0')
			check_sb(var);
		else if (tab[i][0] == 'r' && tab[i][1] == 'a' && tab[i][2] == '\0')
			check_ra(var);
		else
			suite(tab, var, i);
		i++;
	}
}

void	checkit(char **etapes, t_all *var)
{
	int	i;

	var->top = var->topa;
	var->topb = 0;
	i = 0;
	do_it(etapes, var);
	i = 0;
	while (i < var->top - 1)
	{
		if (var->taba[i] < var->taba[i + 1])
			i++;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
}

char	**ft_read(char **etapes)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	if (!(etapes = (char**)malloc(sizeof(char*) * 1000000)))
		return (NULL);
	while (get_next_line(0, &buff) == 1)
	{
		j = 0;
		if (!(etapes[i] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
		while (buff[j] && j < 5)
		{
			etapes[i][j] = buff[j];
			j++;
		}
		if (if_ok(etapes[i]) != 1)
			return (NULL);
		i++;
		free(buff);
	}
	free(buff);
	etapes[i] = NULL;
	return (etapes);
}

void	libere(char **etapes, t_all *var)
{
	int	i;

	i = 0;
	if (etapes)
	{
		while (etapes[i])
			free(etapes[i++]);
	}
	if (etapes)
		free(etapes);
	if (var->taba)
		free(var->taba);
	if (var->tabb)
		free(var->tabb);
}

int		main(int argc, char **argv)
{
	int		i;
	t_all	var;
	char	**etapes;

	ft_bzero(&var, sizeof(t_all));
	begin(&var, &i, &etapes);
	if (!(var.taba) || !(var.tabb) || argc < 2)
		return (0);
	takenumbers(&var, argc, argv, &i);
	if (i != 0)
	{
		write(2, "Error\n", 6);
		if (i == 2)
			write(2, "Trop de nombre, mechant !\n", 26);
		libere(etapes, &var);
		return (0);
	}
	if (!(etapes = ft_read(etapes)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	checkit(etapes, &var);
	libere(etapes, &var);
	return (1);
}
