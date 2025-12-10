/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_process_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:15:09 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:15:09 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_line(char *line)
{
	return (ft_strlen(line) == 0 || line[0] == '\n');
}

int	handle_line(t_game *game, char *line, t_counter *counter)
{
	if (is_empty_line(line))
	{
		if (counter->map_started)
		{
			destroy_textures(game);
			return (ft_error("Error: Found empty line inside map"));
		}
		return (1);
	}
	if (parse_single_line(game, line, counter) != 0)
		return (-1);
	return (0);
}

int	read_cub_lines(t_game *game, int fd, t_counter *counter)
{
	char	*line;
	int		result;

	line = get_next_line(fd);
	while (line != NULL)
	{
		result = handle_line(game, line, counter);
		free(line);
		if (result == 1)
		{
			line = get_next_line(fd);
			continue ;
		}
		if (result == -1)
		{
			gnl_free(NULL);
			close(fd);
			return (-1);
		}
		line = get_next_line(fd);
	}
	return (0);
}
