/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 21:49:56 by acombe            #+#    #+#             */
/*   Updated: 2016/11/13 19:33:51 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int i;

	i = 1;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		i++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c)
			s++;
	}
	return (i);
}

static char	*ft_loop(const char *s, char c)
{
	int		k;
	size_t	j;
	char	*i;

	k = 0;
	j = 0;
	while (s[k] != c && s[k] != '\0')
		k++;
	if (!(i = (char*)malloc(sizeof(char) * k + 1)))
		return (NULL);
	k = 0;
	while (s[k] != c && s[k] != '\0')
		i[j++] = s[k++];
	i[j] = '\0';
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == (NULL))
		return (NULL);
	i = ft_count_word(s, c);
	j = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * i + 1)))
		return (NULL);
	while (s[k] == c)
		k++;
	while (s[k] != '\0' && j <= i && s[k] != c)
	{
		tab[j] = ft_loop(&s[k], c);
		while (s[k] != c && s[k])
			k++;
		while (s[k] == c)
			k++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
