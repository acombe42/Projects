/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 00:40:31 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:33:24 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*o;
	unsigned char	*p;

	i = 0;
	o = (unsigned char *)dst;
	p = (unsigned char *)src;
	while (i < n)
	{
		o[i] = p[i];
		i++;
	}
	return (dst);
}
