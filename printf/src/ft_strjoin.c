/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:58:45 by acombe            #+#    #+#             */
/*   Updated: 2017/05/03 18:07:44 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	k;
	char	*p;

	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	if (!(p = (char*)malloc(sizeof(char) * k + 100)))
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s2);
	return (p);
}
