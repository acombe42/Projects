/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 23:02:49 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:25:19 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*o;

	if (n == 0)
		return (s);
	o = (unsigned char *)s;
	i = 0;
	while (i < n)
		o[i++] = (unsigned char)c;
	return (s);
}
