/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoste <acoste@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:44:35 by acoste            #+#    #+#             */
/*   Updated: 2024/07/17 18:01:45 by acoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// int main(void)
// {
// 	int	i;

// 	i = 0;
// 	char	*s = "Testons tout ca f f saf fd sdkf ";
// 	char	**tab = ft_split(s, ' ');
// 	while (tab[i])
// 	{
// 		printf("split : %s\n", tab[i]);
// 		i++;
// 	}
// }
