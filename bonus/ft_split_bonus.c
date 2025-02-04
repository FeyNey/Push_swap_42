/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:05:03 by acoste            #+#    #+#             */
/*   Updated: 2024/07/30 02:05:11 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] == c)
		i++;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
		{
			words++;
		}
		i++;
	}
	return (words);
}

void	write_words(char *tab, char*s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
}

void	freesplit(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	ft_errors();
}

void	tab_split(char **tab, char *s, char c, int lastw)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (word != lastw)
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			tab[word] = malloc(sizeof(char) * (j + 1));
			if (!tab)
				freesplit(tab);
			write_words(tab[word], s + i, c);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		words;

	words = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		exit(EXIT_FAILURE);
	tab_split(tab, s, c, words);
	tab[words] = 0;
	return (tab);
}