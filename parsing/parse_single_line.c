/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:09:08 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:09:08 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_texture_line(char *line)
{
	if (!line || ft_strlen(line) < 3)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	return (0);
}

static int	is_color_line(char *line)
{
	if (!line || ft_strlen(line) < 2)
		return (0);
	if (line[0] == 'F' || line[0] == 'C')
		return (1);
	return (0);
}

static int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	parse_single_line(t_game *game, char *line, t_counter *counter)
{
	if (is_texture_line(line) && !counter->map_started)
		return (handle_texture_line(game, line, counter));
	else if (is_color_line(line) && !counter->map_started)
		return (handle_color_line(game, line, counter));
	else if (is_map_line(line))
		return (handle_map_line(game, line, counter));
	else
	{
		destroy_textures(game);
		return (ft_error("Error: Unknown line format"));
	}
	return (0);
}
