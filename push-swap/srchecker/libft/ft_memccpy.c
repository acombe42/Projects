/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:02:40 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:22:41 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*o;
	char	*p;

	o = (char *)dst;
	p = (char *)src;
	while (0 < n)
	{
		*o = *p;
		if (*o == c)
		{
			o++;
			return (o);
		}
		n--;
		o++;
		p++;
	}
	return (NULL);
}
