/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:46:31 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 12:33:53 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	j;
	char	*p;
	char	*q;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	if (!(p = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	q = p;
	while (s[i])
	{
		q[i] = (f)(s[i]);
		i++;
	}
	q[i] = '\0';
	return ((char*)p);
}
