/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:08:56 by acombe            #+#    #+#             */
/*   Updated: 2016/11/22 15:09:47 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	j;
	size_t	save;
	size_t	save_1;
	size_t	save_2;

	j = 0;
	while (dst[j])
		j++;
	save_1 = ft_strlen(dst);
	save_2 = ft_strlen(src);
	save = j;
	len = 0;
	while (src[len] && len + save_1 < size - 1)
	{
		dst[j] = src[len];
		j++;
		len++;
	}
	if (j != save)
		dst[j] = '\0';
	if (save_1 > size)
		return (save_2 + size);
	return (save_1 + save_2);
}
