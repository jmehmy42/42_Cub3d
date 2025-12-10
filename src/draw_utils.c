/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:40:55 by belinore          #+#    #+#             */
/*   Updated: 2025/12/08 19:10:36 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_img *img, t_point p0, t_point p1, int color)
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
	while (i <= steps)
	{
		put_pixel(img, round(p.x), round(p.y), color);
		p.x += step.x;
		p.y += step.y;
		i++;
	}
}

void	draw_circle(t_img *img, t_point center, int radius, int color)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			dx = center.x + x;
			dy = center.y + y;
			if (x * x + y * y <= radius * radius)
				put_pixel(img, dx, dy, color);
			x++;
		}
		y++;
	}
}

t_point	get_last_pixel(t_game *g, t_point *start_pixel)
{
	t_point	end;

	end.x = start_pixel->x + g->minimap.tile_size;
	end.y = start_pixel->y + g->minimap.tile_size;
	if (end.x > g->minimap.width_pix)
		end.x = g->minimap.width_pix;
	if (end.y > g->minimap.height_pix)
		end.y = g->minimap.height_pix;
	return (end);
}

void	draw_tile(t_game *g, t_point pixel, int color)
{
	t_point	end;
	int		start_x;

	if (pixel.x >= g->minimap.width_pix || pixel.y >= g->minimap.height_pix)
		return ;
	end = get_last_pixel(g, &pixel);
	start_x = pixel.x;
	while (pixel.y < end.y)
	{
		pixel.x = start_x;
		while (pixel.x < end.x)
		{
			if (pixel.x >= 0 && pixel.x < WIDTH
				&& pixel.y >= 0 && pixel.y < HEIGHT)
				put_pixel(&g->img, pixel.x, pixel.y, color);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_scaled_texture_tile(t_game *g, t_img *tex_img,
		t_point *start_pixel)
{
	t_point		tex;
	t_pointf	step;
	int			i;
	int			j;
	t_point		end_pixel;

	step.x = (float)tex_img->width / g->minimap.tile_size;
	step.y = (float)tex_img->height / g->minimap.tile_size;
	end_pixel = get_last_pixel(g, start_pixel);
	i = 0;
	while (start_pixel->y + i < end_pixel.y)
	{
		tex.y = (int)(i * step.y);
		j = 0;
		while (start_pixel->x + j < end_pixel.x)
		{
			tex.x = (int)(j * step.x);
			if (start_pixel->x + j >= 0 && start_pixel->x + j < WIDTH
				&& start_pixel->y + i >= 0 && start_pixel->y + i < HEIGHT)
				put_pixel(&g->img, start_pixel->x + j, start_pixel->y + i,
					get_tex_pixel(tex_img, tex.x, tex.y));
			j++;
		}
		i++;
	}
}
