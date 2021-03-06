/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:35:45 by acombe            #+#    #+#             */
/*   Updated: 2017/03/21 11:53:46 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (0);
}
