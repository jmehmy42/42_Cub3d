/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-06 11:14:25 by jmehmy            #+#    #+#             */
/*   Updated: 2025-12-06 11:14:25 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	process_cell_player(t_game *game, int i, int j, int *count)
{
	char	c;

	c = game->map.grid[i][j];
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return ;
	(*count)++;
}

int	validate_and_store_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (game->map.grid[i] && game->map.grid[i][j])
		{
			process_cell_player(game, i, j, &count);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (destroy_textures(game),
			ft_error("Error: No Player Found in map"));
	if (count > 1)
		return (destroy_textures(game),
			ft_error("Error: Multiple players found in map only one allowed"));
	return (0);
}
