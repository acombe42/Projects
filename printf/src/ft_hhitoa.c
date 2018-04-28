/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:30:03 by acombe            #+#    #+#             */
/*   Updated: 2017/05/07 15:09:58 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_len(int nb)
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

char			*ft_ope(int n, char *str, int *i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
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

char			*ft_hhitoa(int nb)
{
	signed char	n;
	int			j;
	static int	i[10];
	int			k;
	char		*str;

	n = nb;
	k = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_len(nb)) + 1)))
		return (NULL);
	if (nb == 128 || nb == -128)
		str = "-128";
	if (nb == 128 || nb == -128)
		return (str);
	str = ft_ope(n, str, i);
	return (str);
}
