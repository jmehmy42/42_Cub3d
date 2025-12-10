/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:15:25 by belinore          #+#    #+#             */
/*   Updated: 2025/12/03 19:21:54 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_wall_texture(t_game *g, t_ray *ray)
{
	t_img	*tex;

	if (ray->hit_side == 0)
	{
		if (ray->dir_x > 0)
			tex = &g->textures.east;
		else
			tex = &g->textures.west;
	}
	else
	{
		if (ray->dir_y > 0)
			tex = &g->textures.south;
		else
			tex = &g->textures.north;
	}
	return (tex);
}

//step is how much to increase the texture coordinate per screen pixel
//tex_pos is the initial texture coordinate
////wall->tex_y = (int)tex_pos & (wall->texture->height - 1);
//	performance alternative - bitwise is faster than modulo for powers of two
//wall_y = y - wall_top_y;//tex_y = scale(wall_y, 0, tex->height, wall_height);
//	results in slanted texture when wall_height is greater that HEIGHT
void	draw_wall_slice(t_game *g, t_wall *wall)
{
	double	step;
	double	tex_pos;
	int		color;
	int		y;

	step = wall->texture->height / (double)wall->height;
	tex_pos = step * (wall->top_y - g->mouse_y + wall->height / 2);
	y = wall->top_y;
	while (y < wall->bottom_y)
	{
		wall->tex_y = (int)tex_pos % wall->texture->height;
		tex_pos += step;
		color = get_tex_pixel(wall->texture, wall->tex_x, wall->tex_y);
		put_pixel(&g->img, wall->column, y, color);
		y++;
	}
}

//wall_hit_pos is a scalar value representing the position along the wall
//where the ray hit (from 0 to 1). it is computed by taking the fractional part
void	calc_wall_height_and_texture(t_game *g, t_ray *ray, int column)
{
	t_wall	*wall;
	double	wall_hit_pos;

	wall = &ray->wall;
	wall->column = column;
	wall->height = (int)(g->dist_to_camera_plane / ray->perp_wall_dist);
	wall->top_y = (g->mouse_y) - (wall->height / 2);
	wall->bottom_y = (g->mouse_y) + (wall->height / 2);
	if (wall->top_y < 0)
		wall->top_y = 0;
	if (wall->bottom_y >= HEIGHT)
		wall->bottom_y = HEIGHT - 1;
	wall->texture = get_wall_texture(g, ray);
	if (ray->hit_side == VERTICAL_GRIDLINE)
		wall_hit_pos = wall->hit_pos_y - floor(wall->hit_pos_y);
	else
		wall_hit_pos = wall->hit_pos_x - floor(wall->hit_pos_x);
	wall->tex_x = (int)(wall_hit_pos * (double)wall->texture->width);
	if (ray->hit_side == 0 && ray->dir_x > 0)
		wall->tex_x = wall->texture->width - wall->tex_x - 1;
	if (ray->hit_side == 1 && ray->dir_y < 0)
		wall->tex_x = wall->texture->width - wall->tex_x - 1;
}
