/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:18:30 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 20:25:21 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		put_data(t_parse *elem, char *line, t_env *env)
{
	elem->line = ft_strdup(line);
	elem->op_name = NULL;
	elem->label_name = NULL;
	elem->content_size = 0;
	elem->form.dir_instruct = 1;
	elem->form.labeled_instruct = 0;
	elem->form.only_label = 0;
	elem->form.has_ocp = 0;
	elem->params = NULL;
	elem->binary = NULL;
	elem->form.line_in_file = env->line_nbr;
}

void			add_instruction(char *line, t_parse **buff, t_env *env)
{
	t_parse		*elem;

	if (!(elem = (t_parse*)malloc(sizeof(t_parse) * 1)))
		return ;
	put_data(elem, line, env);
	if (buff)
	{
		if (elem)
			elem->next = *buff;
		*buff = elem;
	}
	else
	{
		*buff = elem;
		elem->next = NULL;
	}
}
