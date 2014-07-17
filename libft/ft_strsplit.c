/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcassagn <mcassagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 15:37:45 by mcassagn          #+#    #+#             */
/*   Updated: 2014/04/15 15:51:27 by mcassagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	count_words(char *s, char c)
{
	unsigned int	words;

	words = 1;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			words++;
		}
		if (*s)
			s++;
	}
	return (words);
}

static unsigned int	mystrlen(char *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char				**ft_strsplit(char *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	k;
	unsigned int	l;

	if (!s || \
		!(tab = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!(tab[k] = (char *)malloc(sizeof(char) * (mystrlen(s, c) + 1))))
			return (NULL);
		l = 0;
		while (s[i] && s[i] != c)
			tab[k][l++] = s[i++];
		tab[k++][l] = '\0';
		if (s[i])
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
