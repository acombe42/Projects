/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_process_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:19:25 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:19:29 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_width(char **data, int *size, t_specifiers specifiers)
{
	int		width;
	char	*to_add;
	char	*tmp;

	width = specifiers.width;
	if (width > *size)
	{
		tmp = *data;
		if (specifiers.flags.zero == 0 || specifiers.flags.dash == 1)
			to_add = ft_strcnew(width - *size, ' ');
		else
			to_add = ft_strcnew(width - *size, '0');
		if (to_add == NULL)
			return ;
		if (specifiers.flags.dash == 0)
			*data = ft_strjoin(to_add, *data);
		else
			*data = ft_strjoin(*data, to_add);
		*size = width;
		free(tmp);
		free(to_add);
	}
}

void		ftpf_process_data(char **data, int *size, t_specifiers specifiers)
{
	if (specifiers.identifier == 'n')
		return ;
	else if (ftpf_is_unsigned_conv(specifiers.identifier))
		ftpf_process_unsigned(data, size, specifiers);
	else if (ftpf_is_signed_conv(specifiers.identifier))
		ftpf_process_signed(data, size, specifiers);
	else if (ftpf_is_characters_conv(specifiers.identifier))
		ftpf_process_characters(data, size, specifiers);
	else
	{
		if (specifiers.width > 0)
			apply_width(data, size, specifiers);
	}
}
