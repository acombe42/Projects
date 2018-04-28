/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:06:52 by acombe            #+#    #+#             */
/*   Updated: 2016/11/28 18:22:55 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_itoa(int nb)
{
	long int	n;
	int			j;
	static int	i[10];
	int			k;
	char		*str;

	n = nb;
	k = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_nblen(nb)) + 1)))
		return (NULL);
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
