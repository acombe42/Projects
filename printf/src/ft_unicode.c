/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:01:13 by acombe            #+#    #+#             */
/*   Updated: 2017/05/05 19:16:35 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

char		*ft_more_unicode(wchar_t c, t_wchar pi, char *save)
{
	pi.d = 0xF0 + (c >> 18);
	pi.e = 0x80 + (c >> 12 & 0x3F);
	pi.f = 0x80 + (c >> 6 & 0x3F);
	pi.g = 0x80 + (c & 0x3F);
	save[0] = pi.d;
	save[1] = pi.e;
	save[2] = pi.f;
	save[3] = pi.g;
	save[4] = '\0';
	return (save);
}

char		*ft_more(wchar_t c, t_wchar pi, char *save)
{
	pi.d = 0xE0 + (c >> 12);
	pi.e = 0x80 + (c >> 6 & 0x3F);
	pi.f = 0x80 + (c & 0x3F);
	save[0] = pi.d;
	save[1] = pi.e;
	save[2] = pi.f;
	save[3] = '\0';
	return (save);
}

char		*ft_unicode(wchar_t c)
{
	t_wchar pi;
	char	*save;

	pi.d = 0;
	save = (char*)malloc(sizeof(char) * 5);
	if (c < 0x80)
	{
		save[0] = c;
		save[1] = '\0';
	}
	else if (c < 0x800)
	{
		pi.d = (c >> 6) + 0xC0;
		pi.e = 0x80 + (c & 0x3F);
		save[0] = pi.d;
		save[1] = pi.e;
		save[2] = '\0';
	}
	else if (c < 0x10000)
		ft_more(c, pi, save);
	else if (c < 0x20000)
		ft_more_unicode(c, pi, save);
	return (save);
}

char		*ft_strunicode(wint_t *wint)
{
	char	*str;
	char	*save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(char) * 16000);
	while (wint[i])
	{
		save = ft_unicode(wint[i]);
		str = ft_strjoin(str, save);
		i++;
		while (str[j])
			j++;
	}
	str[j] = '\0';
	return (str);
}
