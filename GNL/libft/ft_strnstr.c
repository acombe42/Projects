/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:21:58 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 17:30:14 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (little[b] == '\0')
		return ((char*)big);
	while (big[a] != '\0' && a + b < (len))
	{
		b = 0;
		while (big[a + b] == little[b] && little[b] && big[a + b] != '\0'
				&& (a + b) < (len))
			b++;
		if (little[b] == '\0')
			return ((char*)&big[a]);
		a++;
	}
	return (NULL);
}
