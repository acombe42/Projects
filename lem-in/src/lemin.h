/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:41:45 by acombe            #+#    #+#             */
/*   Updated: 2017/08/20 14:51:50 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct	s_all
{
	int		rd;
	char	*str;
	int		ant[200000];
	char	start[100];
	int		stt;
	char	end[100];
	int		fin;
	char	room[1010][1010];
	char	comment[100][200];
	int		chemin[1010];
	int		nbcmde;
	int		nbcmds;
	int		nbroom;
	int		lroom[1010];
	int		coord_x[1010];
	int		coord_y[1010];
	int		links[1010][1010];
	int		pond[1010];
	int		j;
	int		ld;
	int		nbant;
}				t_all;

int				nb_mot(char *str);
void			pond(t_all *all, int *j, int *k, int *n);
void			end(t_all *all);
void			start(t_all *all);
void			parse(t_all *all);
int				ft_isnb(char *str);
long int		ft_atoi(const char *str);
int				check(char *r1, char *r2, t_all *all);
int				linkit(t_all *all, char **r1, char **r2);
void			ft_move(t_all *all);

#endif
