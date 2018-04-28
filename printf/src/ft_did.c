/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_did.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:02 by acombe            #+#    #+#             */
/*   Updated: 2017/05/11 16:26:12 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_did(t_flags flag, char **string, char *str, va_list ap)
{
	int	i;

	i = 0;
	if (flag.h == 1 && str[i] != 'D')
		flag.save = ft_hitoa(va_arg(ap, int));
	else if (flag.h == 2 && str[i] != 'D')
		flag.save = ft_hhitoa(va_arg(ap, int));
	else if (flag.lon == 1 || str[i] == 'D')
		flag.save = ft_litoa(va_arg(ap, long long));
	else
		flag.save = ft_itoa(va_arg(ap, int));
	flag.mode = flag.mode + 1;
	*string = ft_strjoinxfree(*string, flag.save, flag, flag.mode);
	return (flag);
}
