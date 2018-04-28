/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:54:46 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 17:14:24 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	if (n <= 0)
		return (NULL);
	i = 0;
	a = (unsigned char*)s;
	while (a[i] != (unsigned char)c && i < (n - 1))
		i++;
	if (a[i] == (unsigned char)c)
		return (&a[i]);
	return (NULL);
}
