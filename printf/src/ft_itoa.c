/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:06:52 by acombe            #+#    #+#             */
/*   Updated: 2017/05/06 21:24:42 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_nblen(int nb)
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

char			*ft_op(int n, char *str, int *i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	if (n < 0)
		str[k++] = '-';
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

char			*ft_itoa(int nb)
{
	int			n;
	int			j;
	static int	i[10];
	int			k;
	char		*str;

	n = nb;
	k = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_nblen(nb)) + 1)))
		return (NULL);
	if (n == -2147483648)
		str = "-2147483648";
	if (n == -2147483648)
		return (str);
	str = ft_op(n, str, i);
	return (str);
}
