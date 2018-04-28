/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:04:37 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 14:28:27 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	a = (char*)s1;
	b = (char*)s2;
	while (*a == *b && i < (n - 1))
	{
		a++;
		b++;
		i++;
	}
	if (i != n)
		return ((unsigned char)*a - (unsigned char)*b);
	return (0);
}
