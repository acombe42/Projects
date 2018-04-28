/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:04:11 by acombe            #+#    #+#             */
/*   Updated: 2017/05/07 16:57:42 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		nbrlen(unsigned long long int nb)
{
	int i;

	i = 0;
	while (nb > 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_base_lx(unsigned long long int nb, unsigned int base)
{
	char					*str;
	int						i;
	long long unsigned int	j[50];
	int						k;

	str = (char*)malloc(sizeof(char) * nbrlen(nb) + 1);
	i = 0;
	k = 0;
	while (nb >= base)
	{
		j[k] = (nb % base);
		nb = (nb / base);
		k++;
	}
	j[k] = nb;
	while (k > -1)
	{
		if (j[k] >= 10)
			str[i++] = 'a' + j[k--] - 10;
		else
			str[i++] = j[k--] + 48;
	}
	str[i] = '\0';
	return (str);
}
