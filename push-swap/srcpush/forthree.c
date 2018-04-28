/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forthree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:21:31 by acombe            #+#    #+#             */
/*   Updated: 2017/06/07 15:23:53 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	forthree(t_all *val)
{
	if (val->taba[0] > val->taba[1] && val->taba[1] > val->taba[2])
	{
		ra(val);
		sa(val);
	}
	else if (val->taba[0] > val->taba[1] && val->taba[1] < val->taba[2]
			&& val->taba[2] < val->taba[0])
		ra(val);
	else if (val->taba[0] > val->taba[1] && val->taba[1] < val->taba[2]
			&& val->taba[2] > val->taba[0])
		sa(val);
	else if (val->taba[0] < val->taba[1] && val->taba[1] > val->taba[2]
			&& val->taba[2] < val->taba[0])
		rra(val);
	else if (val->taba[0] < val->taba[1] && val->taba[1] > val->taba[2]
			&& val->taba[2] > val->taba[0])
	{
		ra(val);
		sa(val);
		rra(val);
	}
}
