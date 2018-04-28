/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:52:39 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 12:34:07 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(p = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
		p[i++] = (char)s[start++];
	p[i] = '\0';
	return (p);
}
