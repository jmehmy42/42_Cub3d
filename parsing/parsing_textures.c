/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:14:34 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:14:34 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_path(char *line)
{
	char	*path;
	int		i;
	int		j;
	int		start;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i] && line[i] != '\n' && line[i] != ' ')
		i++;
	path = malloc(i - start + 1);
	if (!path)
		return (NULL);
	j = 0;
	while (start < i)
		path[j++] = line[start++];
	path[j] = '\0';
	return (path);
}

static int	set_texture_path(char **dest, char *path)
{
	if (*dest)
		return (-1);
	*dest = ft_strdup(path);
	return (0);
}

static int	assign_texture(t_game *game, char *line, char *path)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture_path(&game->tex_path.north_path, path));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture_path(&game->tex_path.south_path, path));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture_path(&game->tex_path.west_path, path));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture_path(&game->tex_path.east_path, path));
	return (0);
}

int	parse_texture_line(t_game *game, char *line)
{
	char	*path;
	int		result;
	int		fd;

	path = extract_path(line);
	if (!path)
		return (ft_error("Error: Memory allocation failed for texture path"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		destroy_textures(game);
		free(path);
		return (ft_error("Error: Texture file not found or not readable"));
	}
	close(fd);
	result = assign_texture(game, line, path);
	free(path);
	if (result != 0)
	{
		destroy_textures(game);
		return (ft_error("Error: Duplicate texture definition"));
	}
	return (0);
}
