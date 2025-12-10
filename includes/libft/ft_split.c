/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:54:13 by jmehmy            #+#    #+#             */
/*   Updated: 2025/03/06 12:01:02 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != delimiter)
			i++;
	}
	return (count);
}

static int	find_next_word(const char *str, char delimiter, int *start,
		int *end)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && str[i] == delimiter)
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != delimiter)
		i++;
	*end = i;
	return (*start < *end);
}

static void	copy_words(char *tab_word, const char *str, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
	{
		tab_word[j++] = str[start++];
	}
	tab_word[j] = '\0';
}

static int	ft_allocate(char **tab, const char *s, char c)
{
	int	word;
	int	start;
	int	end;
	int	i;

	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(s, c, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], s, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		size;
	char	**new_s;

	if (s == NULL)
		return (NULL);
	size = count_words(s, c);
	new_s = malloc((size + 1) * sizeof(char *));
	if (new_s == NULL)
		return (NULL);
	if (!ft_allocate(new_s, s, c))
	{
		free_string(new_s);
		return (NULL);
	}
	return (new_s);
}
/*
int	main(void) {
	const char *s = "Hello This is ft_split example.";
	char c = ' ';

	char **res = ft_split(s, c);

	if (res != NULL) {
		int i = 0;
		while (res[i] != NULL) {
			printf("Word %d: %s\n", i + 1, res[i]);
			free(res[i]);
			i++;
		}
		free(res);
	} else {
		printf("memory failed.\n");
	}
	return (0);
}
*/
