/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:58:56 by belinore          #+#    #+#             */
/*   Updated: 2025/12/09 16:51:20 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_tile(t_game *g, t_point *pixel, int i, int j)
{
	if (i < 0 || j < 0 || !g->map.grid[i])
		return ;
	else if (!g->map.grid[i][j])
	{
		while (j < g->minimap.tile_offset.x + g->minimap.width_map + 1)
		{
			draw_tile(g, *pixel, DARK_GREY);
			pixel->x += g->minimap.tile_size;
			j++;
		}
		return ;
	}
	else if (g->map.grid[i][j] == '1')
		draw_tile(g, *pixel, BLACK);
	else if (g->map.grid[i][j] == ' ')
		draw_tile(g, *pixel, DARK_GREY);
	else
		draw_tile(g, *pixel, WHITE);
	pixel->x += g->minimap.tile_size;
}

void	draw_full_map(t_game *g)
{
	int		i;
	int		j;
	t_point	pixel;

	i = 0;
	pixel.y = 0;
	while (g->map.grid[i])
	{
		j = 0;
		pixel.x = 0;
		while (g->map.grid[i][j])
		{
			draw_minimap_tile(g, &pixel, i, j);
			if (pixel.x >= WIDTH)
				break ;
			j++;
		}
		pixel.y += g->minimap.tile_size;
		if (pixel.y >= HEIGHT)
			break ;
		i++;
	}
}

static void	calc_offsets(t_game *g, t_point *tile_offset,
	t_point *pixel_offset)
{
	tile_offset->x = (int)(g->minimap.camera.x / g->minimap.tile_size);
	tile_offset->y = (int)(g->minimap.camera.y / g->minimap.tile_size);
	pixel_offset->x = (int)(g->minimap.camera.x) % g->minimap.tile_size;
	pixel_offset->y = (int)(g->minimap.camera.y) % g->minimap.tile_size;
	g->minimap.tile_offset = *tile_offset;
}

void	draw_minimap_view(t_game *g)
{
	int			i;
	int			j;
	t_point		pixel;
	t_point		tile_offset;
	t_point		pixel_offset;

	calc_offsets(g, &tile_offset, &pixel_offset);
	pixel.y = -pixel_offset.y;
	i = tile_offset.y;
	while (i < tile_offset.y + g->minimap.height_map + 1)
	{
		if (i >= 0 && !g->map.grid[i])
			break ;
		j = tile_offset.x;
		pixel.x = -pixel_offset.x;
		while (j < tile_offset.x + g->minimap.width_map + 1)
		{
			draw_minimap_tile(g, &pixel, i, j);
			if (i >= 0 && j >= 0 && !g->map.grid[i][j])
				break ;
			j++;
		}
		pixel.y += g->minimap.tile_size;
		i++;
	}
}

//calculates which part of the map to draw based on player position.
//camera is the top-left pixel of the minimap, with the player in the centre.
//offset_tile is which tile to start drawing from, and offset_pixel enables 
//drawing of partial tiles by shifting start position off the screen.
void	draw_minimap(t_game *g)
{
	if (g->minimap.mode == NO_MAP)
		return ;
	g->minimap.player_pixel.x = (int)(g->player.pos_x * g->minimap.tile_size);
	g->minimap.player_pixel.y = (int)(g->player.pos_y * g->minimap.tile_size);
	if (g->minimap.mode == FULL_MAP || (g->minimap.width_map == g->map.width
			&& g->minimap.height_map == g->map.height))
		draw_full_map(g);
	else
	{
		g->minimap.camera.x = g->minimap.player_pixel.x
			- (g->minimap.width_pix / 2);
		g->minimap.camera.y = g->minimap.player_pixel.y
			- (g->minimap.height_pix / 2);
		if (g->minimap.camera.x < 0)
			g->minimap.camera.x = 0;
		if (g->minimap.camera.y < 0)
			g->minimap.camera.y = 0;
		draw_minimap_view(g);
		g->minimap.player_pixel.x = g->minimap.player_pixel.x
			- g->minimap.camera.x;
		g->minimap.player_pixel.y = g->minimap.player_pixel.y
			- g->minimap.camera.y;
	}
	draw_player(g);
}
