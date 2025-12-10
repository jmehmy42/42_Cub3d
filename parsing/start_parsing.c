/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:15:36 by jmehmy            #+#    #+#             */
/*   Updated: 2025/12/10 13:24:15 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_parsing_completion(t_game *game, t_counter *counter)
{
	if (counter->texture_count != 4)
	{
		destroy_textures(game);
		return (ft_error("Error: Missing texture need NO,SO,WE,EA"));
	}
	if (counter->color_count != 2)
	{
		destroy_textures(game);
		return (ft_error("Error: Missing color need F and C"));
	}
	if (!counter->map_started)
	{
		destroy_textures(game);
		return (ft_error("Error: No map found in file"));
	}
	return (0);
}

int	validate_map(t_game *game)
{
	if (check_valid_chars(game) != 0)
		return (-1);
	if (validate_and_store_player(game) != 0)
		return (-1);
	if (check_map_closed(game) != 0)
		return (-1);
	return (0);
}

int	load_cub_file(t_game *game, const char *path)
{
	t_counter	count;
	int			fd;

	count = (t_counter){0};
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Error: cannot open file"));
	if (read_cub_lines(game, fd, &count) != 0)
		return (-1);
	gnl_free(NULL);
	close(fd);
	if (validate_parsing_completion(game, &count) != 0)
		return (-1);
	return (0);
}

int	is_valid_cub_file(char **argv)
{
	char	*file;

	file = argv[1];
	if (!file || ft_strlen(file) < 5)
		return (ft_error("Error: Invalid file path"));
	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4) != 0)
		return (ft_error("Error: File must have .cub extension"));
	return (0);
}

int	start_parsing(t_game *game, char **argv)
{
	if (is_valid_cub_file(argv) != 0)
		return (-1);
	if (load_cub_file(game, argv[1]) != 0)
	{
		free_map(game);
		return (-1);
	}
	if (validate_map(game) != 0)
	{
		free_map(game);
		return (-1);
	}
	return (0);
}
