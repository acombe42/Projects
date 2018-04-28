/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:19:42 by acombe            #+#    #+#             */
/*   Updated: 2017/05/08 17:18:21 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		nlen(int nb)
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

char	*ft_o(unsigned short nb, unsigned int b, unsigned short *j, char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (nb >= b)
	{
		j[k] = (nb % b);
		nb = (nb / b);
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
	if (i == 0)
		str[i] = '0';
	if (i == 0)
		str[i + 1] = '\0';
	return (str);
}

char	*ft_itoa_base_hx(unsigned short int nb, unsigned int base)
{
	char					*str;
	int						i;
	unsigned short int		j[30];
	int						k;

	str = (char*)malloc(sizeof(char) * nlen(nb) + 1);
	i = 0;
	k = 0;
	str = ft_o(nb, base, j, str);
	return (str);
}
