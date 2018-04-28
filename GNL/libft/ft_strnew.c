/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:26:25 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:31:59 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	s[size] = '\0';
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
