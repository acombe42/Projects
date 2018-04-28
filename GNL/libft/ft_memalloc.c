/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:22:18 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 17:22:24 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	a[size] = '\0';
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
