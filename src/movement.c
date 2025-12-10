/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:05:02 by belinore          #+#    #+#             */
/*   Updated: 2025/12/08 18:53:09 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pointf	get_new_position(t_game *g, double speed, int keycode)
{
	t_pointf	new;

	speed *= g->dt;
	if (keycode == W_KEY || keycode == UP_ARROW)
	{
		new.x = g->player.pos_x + g->player.dir_x * speed;
		new.y = g->player.pos_y + g->player.dir_y * speed;
	}
	else if (keycode == S_KEY || keycode == DOWN_ARROW)
	{
		new.x = g->player.pos_x - g->player.dir_x * speed;
		new.y = g->player.pos_y - g->player.dir_y * speed;
	}
	if (keycode == D_KEY)
	{
		new.x = g->player.pos_x + g->player.plane_x * speed;
		new.y = g->player.pos_y + g->player.plane_y * speed;
	}
	else if (keycode == A_KEY)
	{
		new.x = g->player.pos_x - g->player.plane_x * speed;
		new.y = g->player.pos_y - g->player.plane_y * speed;
	}
	return (new);
}

int	is_valid_move(t_game *g, double x, double y)
{
	double	r;

	r = PLAYER_RADIUS;
	if (g->map.grid[(int)(y + r)][(int)(x + r)] == '1' || g->map.grid[(int)(y
			+ r)][(int)(x - r)] == '1' || g->map.grid[(int)(y - r)][(int)(x
			+ r)] == '1' || g->map.grid[(int)(y - r)][(int)(x - r)] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *g, double speed, int keycode)
{
	t_pointf	new;

	new = get_new_position(g, speed, keycode);
	if (new.x < 0 || new.x >= g->map.width || new.y < 0
		|| new.y >= g->map.height)
		return ;
	if (is_valid_move(g, new.x, g->player.pos_y))
	{
		g->player.pos_x = new.x;
		g->player.map_x = (int)new.x;
	}
	if (is_valid_move(g, g->player.pos_x, new.y))
	{
		g->player.pos_y = new.y;
		g->player.map_y = (int)new.y;
	}
}

void	rotate_player(t_game *g, double rot_speed_radians)
{
	double		old_dir_x;
	double		old_plane_x;
	double		cos_angle;
	double		sin_angle;
	t_player	*player;

	player = &g->player;
	rot_speed_radians *= g->dt;
	cos_angle = cos(rot_speed_radians);
	sin_angle = sin(rot_speed_radians);
	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos_angle - player->dir_y * sin_angle;
	player->dir_y = old_dir_x * sin_angle + player->dir_y * cos_angle;
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos_angle - player->plane_y * sin_angle;
	player->plane_y = old_plane_x * sin_angle + player->plane_y * cos_angle;
}

void	handle_events(t_game *g)
{
	if (g->key_states.move_forward)
		move_player(g, MOVE_SPEED, W_KEY);
	if (g->key_states.move_backward)
		move_player(g, MOVE_SPEED, S_KEY);
	if (g->key_states.strafe_right)
		move_player(g, MOVE_SPEED, D_KEY);
	if (g->key_states.strafe_left)
		move_player(g, MOVE_SPEED, A_KEY);
	if (g->key_states.rotate_right)
		rotate_player(g, ROTATION_SPEED);
	if (g->key_states.rotate_left)
		rotate_player(g, -ROTATION_SPEED);
}
