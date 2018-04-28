/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:26:36 by acombe            #+#    #+#             */
/*   Updated: 2017/06/23 18:53:38 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srchecker/get_next_line.h"

typedef	struct	s_all
{
	int	*taba;
	int	*tabb;
	int	*tabfinal;
	int	*tabmed;
	int	topa;
	int	topb;
	int	top;
	int	medall;
	int medx[80];
	int	j;
	int	i;
	int coup;
	int	count;
	int	nb;
}				t_all;

long int		ft_atoi(const char *str);
int				checko(t_all *val);
void			ft_affich(t_all *val);
void			finishhim(t_all *val);
int				checker(t_all *val);
void			trithree(t_all *val);
void			begin(t_all *var, int *i, char ***etapes);
void			forthree(t_all *val);
void			fiftyfifty(t_all *val);
int				checka(t_all *val);
int				ft_is_a_nb(char *str);
int				higher(t_all *val, int i);
void			little(t_all *val);
int				medx(t_all *val);
void			takemedx(t_all *val);
void			onlythree(t_all *val);
int				ft_true(t_all *val);
int				ft_tru(t_all *val);
void			end(t_all *val);
int				if_ok(char *str);
void			lasttri(t_all *val);
void			suite(char **tab, t_all *var, int i);
int				is_here(char *str, t_all *var, int j);
void			rrb(t_all *val);
int				littlecheck(t_all *val);
void			rb(t_all *val);
void			check_rrb(t_all *val);
void			check_rrr(t_all *val);
void			check_rr(t_all *val);
void			check_rb(t_all *val);
void			rra(t_all *val);
void			ra(t_all *val);
void			check_rra(t_all *val);
void			check_ra(t_all *val);
void			rr(t_all *val);
void			rrr(t_all *val);
void			check_rr(t_all *val);
void			check_rrr(t_all *val);
void			ss(t_all *val);
void			check_ss(t_all *val);
void			pa(t_all *val);
void			pb(t_all *val);
void			sa(t_all *val);
void			sb(t_all *val);
void			check_pa(t_all *val);
void			check_pb(t_all *val);
void			check_sa(t_all *val);
void			check_sb(t_all *val);
void			tabfinal(t_all *val);
void			tri(t_all *val);
void			takethreeorless(t_all *val);
void			trilesscount(t_all *val);
void			takelastmed(t_all *val);
void			takenumbers(t_all *val, int argc, char **argv, int *i);
int				check(t_all *val);

#endif
