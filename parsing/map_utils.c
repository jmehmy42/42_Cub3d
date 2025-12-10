/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:00:26 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:00:26 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_not_close(t_game *game, char n, char *c)
{
	if (!n)
	{
		destroy_textures(game);
		if (ft_strncmp(c, "x-1", 3) == 0)
			return (ft_error("Error: Map is not closed on the left border"));
		if (ft_strncmp(c, "x+1", 3) == 0)
			return (ft_error("Error: Map is not closed on the Right border"));
		if (ft_strncmp(c, "y+1", 3) == 0)
			return (ft_error("Error: Map is not closed on the Bottom border"));
		if (ft_strncmp(c, "y-1", 3) == 0)
			return (ft_error("Error: Map is not closed on the Top border"));
	}
	return (0);
}

static int	is_valid_neighbor(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->map.height)
		return (0);
	if (x < 0)
		return (0);
	if (!game->map.grid[y])
		return (0);
	if (x >= (int)ft_strlen(game->map.grid[y]))
		return (0);
	return (1);
}

static int	check_neighbors(t_game *game, int x, int y)
{
	char	n;

	n = is_valid_neighbor(game, x - 1, y);
	if (map_not_close(game, n, "x-1") != 0)
		return (1);
	n = is_valid_neighbor(game, x + 1, y);
	if (map_not_close(game, n, "x+1") != 0)
		return (1);
	n = is_valid_neighbor(game, x, y - 1);
	if (map_not_close(game, n, "y-1") != 0)
		return (1);
	n = is_valid_neighbor(game, x, y + 1);
	if (map_not_close(game, n, "y+1") != 0)
		return (1);
	return (0);
}

int	check_valid_chars(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.grid[i] && game->map.grid[i][j])
		{
			c = game->map.grid[i][j];
			if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W')
			{
				destroy_textures(game);
				return (ft_error("Error: Invalid character in map"));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_closed(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y] && game->map.grid[y][x])
		{
			c = game->map.grid[y][x];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (check_neighbors(game, x, y) != 0)
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
