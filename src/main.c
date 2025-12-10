/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:03:53 by belinore          #+#    #+#             */
/*   Updated: 2025/12/10 10:15:46 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_display_and_exit(t_game *g, char *msg)
{
	free_map(g);
	destroy_textures(g);
	if (g->img.img_ptr)
		mlx_destroy_image(g->mlx, g->img.img_ptr);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		mlx_loop_end(g->mlx);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (msg)
	{
		perror(msg);
		exit (1);
	}
	printf("Exiting...\n");
	exit (0);
}

void	init_game(t_game *game)
{
	game->floor_color = (t_color){50, 50, 50};
	game->ceiling_color = (t_color){135, 206, 235};
	game->mouse_x = WIDTH / 2;
	game->mouse_y = HEIGHT / 2;
	game->fov = PI / 3;
	game->minimap.tile_size = (int)(HEIGHT * 0.04);
}

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
	{
		return (ft_error("map.cub file is missing"), 1);
	}
	init_game(&game);
	if (start_parsing(&game, argv) != 0)
		return (1);
	init_mlx(&game);
	init_textures(&game);
	init_player(&game);
	init_camera(&game);
	init_hooks(&game);
	mlx_loop(game.mlx);
}
