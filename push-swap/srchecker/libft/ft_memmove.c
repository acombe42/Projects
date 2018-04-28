/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:58:10 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:44:45 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revcopy(void *dst, const void *src, size_t n)
{
	char *a;
	char *b;

	a = (char*)dst;
	b = (char*)src;
	while (n--)
		a[n] = b[n];
	return (a);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		dst = ft_revcopy(dst, src, len);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
