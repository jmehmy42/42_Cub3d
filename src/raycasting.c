/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:08:19 by belinore          #+#    #+#             */
/*   Updated: 2025/12/03 19:16:25 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Jump to next map square, either in x-direction, or in y-direction
//if distance to next x-side is less than distance to next y-side
//move to next x-side; step in x-direction; hit side = vertical gridline
//else move to next y-side; step in y-direction; hit side is horizontal gridl
void	move_to_next_gridline(t_ray *ray, int *map_x, int *map_y)
{
	if (ray->total_dist_x < ray->total_dist_y)
	{
		ray->total_dist_x += ray->delta_dist_x;
		*map_x += ray->step_x;
		ray->hit_side = VERTICAL_GRIDLINE;
	}
	else
	{
		ray->total_dist_y += ray->delta_dist_y;
		*map_y += ray->step_y;
		ray->hit_side = HORIZONAL_GRIDLINE;
	}
}

//Raycasting DDA algorithm to find wall hit
//Starting from player position, step through map grid until a wall is hit
//side_dist, delta_dist and ray_dir are pre-calculated
//When a wall is hit, calc perpendicular distance to wall & exact hit position
//it is total_dist - delta_dist since we detected the wall on the last step,
//	and want to stop on the map square before the wall.
//wall.hit_pos is calculated by adding the distance from player along ray dir
void	cast_ray(t_game *g, t_ray *ray)
{
	int	map_x;
	int	map_y;
	int	hit;

	ray->total_dist_x = ray->side_dist_x;
	ray->total_dist_y = ray->side_dist_y;
	map_x = g->player.map_x;
	map_y = g->player.map_y;
	hit = 0;
	while (hit == 0)
	{
		move_to_next_gridline(ray, &map_x, &map_y);
		if (g->map.grid[map_y][map_x] == '1')
		{
			hit = 1;
			ray->wall.map_tile_x = map_x;
			ray->wall.map_tile_y = map_y;
		}
	}
	if (ray->hit_side == VERTICAL_GRIDLINE)
		ray->perp_wall_dist = ray->total_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->total_dist_y - ray->delta_dist_y;
	ray->wall.hit_pos_x = g->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall.hit_pos_y = g->player.pos_y + ray->perp_wall_dist * ray->dir_y;
}

//Calculate ray direction for each column of the screen
//ray direction is the sum of the player direction vector
//	and the scaled camera plane vector
void	calc_ray_direction(t_game *g, t_ray *ray, int column)
{
	ray->camera_x = g->camera_x[column];
	ray->dir_x = g->player.dir_x + g->player.plane_x * ray->camera_x;
	ray->dir_y = g->player.dir_y + g->player.plane_y * ray->camera_x;
	if (ray->dir_x == 0)
		ray->dir_x = 1e-9;
	if (ray->dir_y == 0)
		ray->dir_y = 1e-9;
}

//Calculate step and initial side distances for DDA algorithm
//if ray->dir_x < 0, ray is pointing left, so step_x is -1
//side_dist_x is the distance from the ray's starting position to the 
//first x side / vertical gridline.
//delta_dist_x is the distance the ray must travel to cross one x grid line
//delta_dist_x = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
//		i.e. pythagorean theorem for calculating the hypotenuse
//it can be simplified to deltaDistX = abs(|rayDir| / rayDirX)
//then abs(1 / rayDirX) because we only care about the ratio of the sides,
//	not the actual lengths
void	calc_dda_distances(t_ray *ray, t_player *player)
{
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - player->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (player->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - player->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (player->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	raycasting(t_game *g)
{
	t_ray	*ray;
	int		column;

	column = 0;
	while (column < WIDTH)
	{
		ray = &g->rays[column];
		calc_ray_direction(g, ray, column);
		calc_dda_distances(ray, &g->player);
		cast_ray(g, ray);
		calc_wall_height_and_texture(g, ray, column);
		draw_wall_slice(g, &ray->wall);
		column++;
	}
	return ;
}
