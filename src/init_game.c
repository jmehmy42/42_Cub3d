/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:53:14 by belinore          #+#    #+#             */
/*   Updated: 2025/12/09 18:07:52 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_camera(t_game *g)
{
	double	camera_plane_scale;
	int		x;

	camera_plane_scale = tan(g->fov / 2);
	g->player.plane_x = -g->player.dir_y * camera_plane_scale;
	g->player.plane_y = g->player.dir_x * camera_plane_scale;
	g->dist_to_camera_plane = (WIDTH / 2) / tan(g->fov / 2);
	x = 0;
	while (x < WIDTH)
	{
		g->camera_x[x] = scale_pixel(x, -1.0, 1.0, WIDTH - 1);
		x++;
	}
}

//defines minimap default size and adjusts if map/screen size is smaller
void	init_minimap(t_game *g)
{
	g->minimap.width_map = 9;
	g->minimap.height_map = 7;
	if (g->map.width <= g->minimap.width_map)
		g->minimap.width_map = g->map.width;
	if (g->map.height <= g->minimap.height_map)
		g->minimap.height_map = g->map.height;
	g->minimap.width_pix = g->minimap.width_map * g->minimap.tile_size;
	g->minimap.height_pix = g->minimap.height_map * g->minimap.tile_size;
	if (g->minimap.width_pix >= WIDTH)
	{
		g->minimap.width_map = (int)WIDTH / g->minimap.tile_size + 1;
		g->minimap.width_pix = WIDTH;
	}
	if (g->minimap.height_pix >= HEIGHT)
	{
		g->minimap.height_map = (int)HEIGHT / g->minimap.tile_size + 1;
		g->minimap.height_pix = HEIGHT;
	}
}

void	set_player_direction(t_game *g, char direction)
{
	if (direction == 'N')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
	}
	else if (direction == 'S')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
	}
	else if (direction == 'E')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
	}
	else if (direction == 'W')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
	}
}

void	init_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map.grid[y])
	{
		x = 0;
		while (g->map.grid[y][x])
		{
			if (g->map.grid[y][x] == 'N' || g->map.grid[y][x] == 'S'
				|| g->map.grid[y][x] == 'E' || g->map.grid[y][x] == 'W')
			{
				g->player.map_x = x;
				g->player.map_y = y;
				g->player.pos_x = x + 0.5;
				g->player.pos_y = y + 0.5;
				set_player_direction(g, g->map.grid[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}
