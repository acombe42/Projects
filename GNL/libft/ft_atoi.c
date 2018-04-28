/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:02:21 by acombe            #+#    #+#             */
/*   Updated: 2017/01/28 16:30:11 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			neg;

	nb = 0;
	neg = 0;
	i = 0;
	while (str[i] == 9 || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '-' || str[i] == '+' || str[i] == ' '
			|| str[i] == '\r')
	{
		if (str[i] == '-')
			neg = 1;
		if ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (nb);
		i++;
	}
	if (str[i] == '\0')
		return (nb);
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - 48);
	if (neg == 1)
		nb = nb * -1;
	return (nb);
}
