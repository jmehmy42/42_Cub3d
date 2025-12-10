/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:11:45 by belinore          #+#    #+#             */
/*   Updated: 2025/12/08 19:40:37 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_minimap_mode(t_game *g)
{
	g->minimap.mode = (g->minimap.mode + 1) % 3;
	if (g->minimap.mode == PARTIAL_MAP)
		init_minimap(g);
	else if (g->minimap.mode == FULL_MAP)
	{
		g->minimap.width_map = g->map.width;
		g->minimap.height_map = g->map.height;
		g->minimap.width_pix = g->minimap.width_map * g->minimap.tile_size;
		g->minimap.height_pix = g->minimap.height_map * g->minimap.tile_size;
		g->minimap.camera.x = 0;
		g->minimap.camera.y = 0;
	}
}

void	draw_ray_minimap(t_game *g, t_point p0, t_point p1, int color)
{
	t_point		d;
	int			steps;
	t_pointf	step;
	t_pointf	p;
	int			i;

	d.x = p1.x - p0.x;
	d.y = p1.y - p0.y;
	steps = max(iabs(d.x), iabs(d.y));
	if (steps == 0)
		return ;
	step.x = (double)d.x / steps;
	step.y = (double)d.y / steps;
	p.x = (double)p0.x;
	p.y = (double)p0.y;
	i = 0;
	while (i++ <= steps)
	{
		if ((round)(p.x) < 0 || round(p.x) >= g->minimap.width_pix
			|| round(p.y) < 0 || round(p.y) >= g->minimap.height_pix)
			return ;
		put_pixel(&g->img, round(p.x), round(p.y), color);
		p.x += step.x;
		p.y += step.y;
	}
}

//raycasting visualisaton on minimap using data from stored rays
void	raycasting_minimap(t_game *g)
{
	t_ray	*ray;
	t_point	wall_hit_pixel;
	t_point	wall_map_pixel;
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		ray = &g->rays[i];
		wall_hit_pixel.x = (int)(ray->wall.hit_pos_x * g->minimap.tile_size
				- g->minimap.camera.x);
		wall_hit_pixel.y = (int)(ray->wall.hit_pos_y * g->minimap.tile_size
				- g->minimap.camera.y);
		draw_ray_minimap(g, g->minimap.player_pixel, wall_hit_pixel, GREEN);
		wall_map_pixel.x = (int)(ray->wall.map_tile_x * g->minimap.tile_size
				- g->minimap.camera.x);
		wall_map_pixel.y = (int)(ray->wall.map_tile_y * g->minimap.tile_size
				- g->minimap.camera.y);
		draw_scaled_texture_tile(g, ray->wall.texture, &wall_map_pixel);
		i++;
	}
}

void	draw_player(t_game *g)
{
	t_point	circle_center;
	t_point	line_end;
	int		radius;
	int		line_len;

	circle_center.x = g->minimap.player_pixel.x;
	circle_center.y = g->minimap.player_pixel.y;
	if (circle_center.x < 0 || circle_center.x >= WIDTH
		|| circle_center.y < 0 || circle_center.y >= HEIGHT)
		return ;
	radius = g->minimap.tile_size / 4;
	draw_circle(&g->img, circle_center, radius, YELLOW);
	if (DEBUG_MODE)
		raycasting_minimap(g);
	line_len = g->minimap.tile_size / 3;
	line_end.x = circle_center.x + g->player.dir_x * line_len;
	line_end.y = circle_center.y + g->player.dir_y * line_len;
	draw_line(&g->img, circle_center, line_end, RED);
}
