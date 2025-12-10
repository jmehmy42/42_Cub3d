/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:48 by belinore          #+#    #+#             */
/*   Updated: 2025/12/08 19:38:48 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_game *g)
{
	destroy_display_and_exit(g, NULL);
	return (0);
}

void	update_key_states(int keycode, t_keys *keys, int toggle)
{
	if (keycode == W_KEY || keycode == UP_ARROW)
		keys->move_forward = toggle;
	else if (keycode == S_KEY || keycode == DOWN_ARROW)
		keys->move_backward = toggle;
	else if (keycode == D_KEY)
		keys->strafe_right = toggle;
	else if (keycode == A_KEY)
		keys->strafe_left = toggle;
	else if (keycode == LEFT_ARROW)
		keys->rotate_left = toggle;
	else if (keycode == RIGHT_ARROW)
		keys->rotate_right = toggle;
}

int	key_handler(int keycode, t_game *g)
{
	if (keycode == P_KEY)
		g->key_states.pause = !g->key_states.pause;
	else if (keycode == ENTER_KEY)
	{
		g->fov += 5 * PI / 180;
		init_camera(g);
	}
	else if (keycode == BACKSPACE)
	{
		g->fov -= 5 * PI / 180;
		init_camera(g);
	}
	else if (keycode == M_KEY)
		update_minimap_mode(g);
	else if (keycode == ESC)
		destroy_display_and_exit(g, NULL);
	else
		update_key_states(keycode, &g->key_states, 1);
	return (0);
}

int	key_release_handler(int keycode, t_game *g)
{
	update_key_states(keycode, &g->key_states, 0);
	return (0);
}

int	mouse_move_handler(int x, int y, t_game *g)
{
	int		dx;
	double	rot_speed;

	if (g->key_states.pause || x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	g->mouse_y = HEIGHT - y;
	dx = x - g->mouse_x;
	if (dx == 0)
		return (0);
	rot_speed = dx * MOUSE_SENSITIVITY;
	rotate_player(g, rot_speed);
	if (x == 0)
		g->mouse_x = x + 7;
	else if (x == WIDTH - 1)
		g->mouse_x = x - 7;
	else
		g->mouse_x = x;
	return (0);
}
