/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:04:32 by acombe            #+#    #+#             */
/*   Updated: 2016/11/14 16:36:02 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*c;
	size_t			i;
	unsigned int	j;
	int				k;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	j = 0;
	while ((s[i + j] == ' ' || s[i + j] == '\t' || s[i + j] == '\n')
			&& s[i + j] != '\0')
		j++;
	if (s[i + j] == '\0')
		return (c = ft_strnew(0));
	while (s[i + j])
		i++;
	i--;
	while ((s[i + j] == ' ' || s[i + j] == '\t' || s[i + j] == '\n')
			&& s[i + j] != '\0')
		i--;
	i++;
	return (c = ft_strsub(s, j, i));
}
