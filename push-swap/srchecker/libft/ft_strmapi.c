/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:49:16 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 12:32:59 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned int	j;
	char			*p;
	char			*q;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (!(p = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	q = p;
	while (*s)
		*q++ = (f)(j++, *s++);
	*q = '\0';
	return ((char*)p);
}
