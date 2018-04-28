/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:20:39 by acombe            #+#    #+#             */
/*   Updated: 2017/05/07 16:07:51 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_nbrlen(long long nb)
{
	int	i;

	i = 0;
	i++;
	if (nb < 0)
		i++;
	while (nb > 9 || nb < -9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_operati(long long n, long long *i, char *str)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (n < 0)
		str[k++] = '-';
	if (n < -9223372036854775807)
		str[k++] = '9';
	if (n < -9223372036854775807)
		n = n % 1000000000000000000;
	if (n < 0)
		n = n * -1;
	while (n > 9)
	{
		i[j++] = (n % 10);
		n = (n / 10);
	}
	i[j] = n;
	while (j > -1)
		str[k++] = i[j--] + 48;
	str[k] = '\0';
	return (str);
}

char			*ft_litoa(long long nb)
{
	long long			n;
	int					j;
	static long long	i[10];
	int					k;
	char				*str;

	n = nb;
	k = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_nbrlen(nb)) + 1)))
		return (NULL);
	str = ft_operati(n, i, str);
	return (str);
}
