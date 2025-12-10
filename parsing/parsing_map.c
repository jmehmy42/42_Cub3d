/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:13:14 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:13:14 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_trimed_len(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

static char	*dup_map_line(char *line, int len)
{
	char	*map_line;
	int		i;

	map_line = ft_calloc(len + 1, sizeof(char));
	if (!map_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map_line[i] = line[i];
		i++;
	}
	return (map_line);
}

static char	**resize_map_grid(char **old_grid, int needed)
{
	char	**new_grid;
	int		i;

	new_grid = ft_calloc(needed, sizeof(char *));
	if (!new_grid)
	{
		ft_error("Error: Memory allocation failed for map grid");
		return (NULL);
	}
	i = 0;
	if (old_grid)
	{
		while (old_grid[i])
		{
			new_grid[i] = old_grid[i];
			i++;
		}
		free(old_grid);
	}
	return (new_grid);
}

int	append_map_line(t_game *game, char *line, int line_index)
{
	int		len;
	char	*map_line;
	char	**new_grid;

	if (!line)
		return (ft_error("Error: NULL line passed to append_map_line"));
	len = get_trimed_len(line);
	map_line = dup_map_line(line, len);
	if (!map_line)
		return (ft_error("Error: Memory allocation failed for map line"));
	new_grid = resize_map_grid(game->map.grid, line_index + 2);
	if (!new_grid)
	{
		free(map_line);
		ft_error("Error: Memory allocation failed for new grid");
		return (-1);
	}
	game->map.grid = new_grid;
	game->map.grid[line_index] = map_line;
	game->map.grid[line_index + 1] = NULL;
	game->map.height = line_index + 1;
	if (len > game->map.width)
		game->map.width = len;
	return (0);
}
