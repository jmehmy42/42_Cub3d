/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:54:13 by jmehmy            #+#    #+#             */
/*   Updated: 2025/03/22 13:44:13 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delimiter)
{
	int	count;
	int	quotes;

	count = 0;
	quotes = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == delimiter)
			str++;
		if (*str != '\0')
			count++;
		while (*str != '\0' && (quotes || *str != delimiter))
		{
			if (*str == '"' || *str == '\'')
			{
				if (quotes == 0)
					quotes = *str;
				else if (quotes == *str)
					quotes = 0;
			}
			str++;
		}
	}
	return (count);
}

static int	find_next_word(const char *str, char delimiter, int *start,
		int *end)
{
	int	i;
	int	quotes;

	i = *end;
	quotes = 0;
	while (str[i] != '\0' && str[i] == delimiter)
		i++;
	*start = i;
	while (str[i] != '\0' && (quotes || str[i] != delimiter))
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			if (quotes == 0)
				quotes = str[i];
			else if (quotes == str[i])
				quotes = 0;
		}
		i++;
	}
	*end = i;
	return (*start < *end);
}

static void	copy_words(char *tab_word, const char *str, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (i < end)
	{
		if (str[i] != '"' && str[i] != '\'')
			tab_word[j++] = str[i];
		i++;
	}
	tab_word[j] = '\0';
}

static int	ft_allocate(char **tab, const char *s, char c)
{
	int	word;
	int	start;
	int	end;

	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(s, c, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			free_string(tab);
			return (0);
		}
		copy_words(tab[word], s, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_splits(const char *s, char c)
{
	int		size;
	char	**new_s;

	if (s == NULL)
		return (NULL);
	size = count_words(s, c);
	if (size == 0)
		return (NULL);
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
