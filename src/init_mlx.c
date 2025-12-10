/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:53:54 by belinore          #+#    #+#             */
/*   Updated: 2025/12/09 14:53:08 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture_to_buffer(t_game *g, t_img *img, char *path, char tex)
{
	img->img_ptr = mlx_xpm_file_to_image(g->mlx, path, &img->width,
			&img->height);
	if (!img->img_ptr && tex == 'N')
		destroy_display_and_exit(g,
			"Error: Failed to load North wall texture; must be a valid .xpm");
	else if (!img->img_ptr && tex == 'S')
		destroy_display_and_exit(g,
			"Error: Failed to load South wall texture; must be a valid .xpm");
	else if (!img->img_ptr && tex == 'E')
		destroy_display_and_exit(g,
			"Error: Failed to load East wall texture; must be a valid .xpm");
	else if (!img->img_ptr && tex == 'W')
		destroy_display_and_exit(g,
			"Error: Failed to load West wall texture; must be a valid .xpm");
	else if (!img->img_ptr)
		destroy_display_and_exit(g,
			"Error: Failed to load texture; must be a valid .xpm.");
	img->pixel_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_length, &img->endian);
}

void	init_textures(t_game *g)
{
	load_texture_to_buffer(g, &g->textures.north, g->tex_path.north_path, 'N');
	load_texture_to_buffer(g, &g->textures.south, g->tex_path.south_path, 'S');
	load_texture_to_buffer(g, &g->textures.east, g->tex_path.east_path, 'E');
	load_texture_to_buffer(g, &g->textures.west, g->tex_path.west_path, 'W');
	g->textures.floor = (g->floor_color.red << 16)
		| (g->floor_color.green << 8) | (g->floor_color.blue);
	g->textures.ceiling = (g->ceiling_color.red << 16)
		| (g->ceiling_color.green << 8) | (g->ceiling_color.blue);
}

void	init_hooks(t_game *g)
{
	mlx_hook(g->window, ON_DESTROY, 1L << 2, close_window, g);
	mlx_hook(g->window, ON_KEYDOWN, 1L << 0, key_handler, g);
	mlx_hook(g->window, ON_MOUSEMOVE, 1L << 6, mouse_move_handler, g);
	mlx_hook(g->window, ON_KEYUP, 1L << 1, key_release_handler, g);
	mlx_loop_hook(g->mlx, render_frame, g);
}

void	init_mlx(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		destroy_display_and_exit(g, "Error: mlx_init failed");
	g->window = mlx_new_window(g->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!g->window)
		destroy_display_and_exit(g, "Error: mlx_new_window failed");
	g->img.img_ptr = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	if (!g->img.img_ptr)
		destroy_display_and_exit(g, "Error: mlx_new_image failed");
	g->img.pixel_ptr = mlx_get_data_addr(g->img.img_ptr, &g->img.bpp,
			&g->img.line_length, &g->img.endian);
}
