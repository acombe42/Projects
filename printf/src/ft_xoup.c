/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:32:56 by acombe            #+#    #+#             */
/*   Updated: 2017/05/11 16:11:54 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_xp(char *str, char *save, t_flags *flag, va_list ap)
{
	int i;

	i = 0;
	if (flag->h == 1 && str[i] != 'p')
		save = ft_itoa_base_hx(va_arg(ap, unsigned int), 16);
	else if (flag->h == 2 && str[i] != 'p')
		save = ft_itoa_base_hhx(va_arg(ap, unsigned int), 16);
	else if (flag->lon != 1 && str[i] != 'p')
		save = ft_itoa_base_x(va_arg(ap, unsigned int), 16);
	else
		save = ft_itoa_base_lx(va_arg(ap, long long unsigned int), 16);
	if (flag->di == 1 && save[0] != '0')
		save = ft_strjoin("0x", save);
	if (str[i] == 'p')
		save = ft_strjoin("0x", save);
	if (str[i] == 'X')
		save = ft_toupper(save);
	return (save);
}

char	*ft_u(char *str, char *save, t_flags *flag, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == 'u' || str[i] == 'U')
	{
		if (flag->h == 1 && str[i] != 'U')
			save = ft_itoa_base_hx(va_arg(ap, unsigned int), 10);
		else if (flag->h == 2 && str[i] != 'U')
			save = ft_itoa_base_hhx(va_arg(ap, unsigned int), 10);
		else if (flag->lon != 1 && str[i] != 'U')
			save = ft_itoa_base_x(va_arg(ap, unsigned int), 10);
		else
			save = ft_itoa_base_lx(va_arg(ap, long unsigned int), 10);
	}
	return (save);
}

char	*ft_oo(char *str, char *save, t_flags *flag, va_list ap)
{
	int	i;

	i = 0;
	if (str[i] == 'o' || str[i] == 'O')
	{
		if (flag->h == 1 && str[i] != 'O')
			save = ft_itoa_base_hx(va_arg(ap, unsigned int), 8);
		else if (flag->h == 2 && str[i] != 'O')
			save = ft_itoa_base_hhx(va_arg(ap, unsigned int), 8);
		else if (flag->lon != 1 && str[i] != 'O')
			save = ft_itoa_base_x(va_arg(ap, unsigned int), 8);
		else
			save = ft_itoa_base_lx(va_arg(ap, long unsigned int), 8);
		if (flag->di == 1)
			save = ft_strjoin("0", save);
	}
	return (save);
}

char	*ft_xoup(char *str, t_flags *flag, char *string, va_list ap)
{
	int	i;

	i = 0;
	flag->sp = 0;
	flag->pl = 0;
	if (str[i] == 'p')
		flag->di = 0;
	if (str[i] == 'U')
		flag->lon = 1;
	flag->mode = flag->mode + 1;
	if (str[i] == 'x' || str[i] == 'X' || str[i] == 'p')
		flag->save = ft_xp(&str[i], flag->save, flag, ap);
	if (str[i] == 'o' || str[i] == 'O')
		flag->save = ft_oo(&str[i], flag->save, flag, ap);
	if (str[i] == 'u' || str[i] == 'U')
		flag->save = ft_u(&str[i], flag->save, flag, ap);
	string = ft_strjoinxfree(string, flag->save, *flag, flag->mode);
	return (string);
}
