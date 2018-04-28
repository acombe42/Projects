/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:17:17 by acombe            #+#    #+#             */
/*   Updated: 2017/01/30 16:17:55 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int mode)
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
	if (!(p = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	if ((mode == 1 || mode == 3) && s1[0])
		free((void*)s1);
	if (mode == 2 || mode == 3)
		free((void*)s2);
	return (p);
}
