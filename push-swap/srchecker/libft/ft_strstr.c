/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:54:07 by acombe            #+#    #+#             */
/*   Updated: 2016/11/08 20:09:54 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (little[b] == '\0')
		return ((char*)big);
	while (big[a])
	{
		b = 0;
		while (big[a + b] == little[b])
		{
			b++;
			if (little[b] == '\0')
				return ((char*)&big[a]);
		}
		if (big[a + b] == '\0')
			return (NULL);
		a++;
		if (big[a] == '\0')
			return (NULL);
	}
	return (NULL);
}
