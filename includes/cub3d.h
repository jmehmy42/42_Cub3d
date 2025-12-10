/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:16:23 by belinore          #+#    #+#             */
/*   Updated: 2025/12/10 12:13:53 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define DEBUG_MODE 1
# define WIDTH 1500//1280 // 640
# define HEIGHT 1000//720 // 400

# define MAX_RAY_LENGTH 1000
# define ROTATION_SPEED 2
# define MOVE_SPEED 2
# define MOUSE_SENSITIVITY 0.5
# define VERTICAL_GRIDLINE 0
# define HORIZONAL_GRIDLINE 1
# define PLAYER_RADIUS 0.15
# define MS_PER_FRAME 1600
# define PI 3.14159265358979323846

# define RED 0xFF0000
# define DARK_RED 0x800000
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x0000FF
# define DARK_BLUE 0x000080
# define YELLOW 0xFFDE21
# define GREEN 0x00FF00
# define LIGHT_GREY 0xD3D3D3
# define DARK_GREY 0x708090
# define BLUE_GREY 0x7393B3

# define ESC 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define P_KEY 112
# define ENTER_KEY 65293
# define BACKSPACE 65288
# define M_KEY 109

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_mode
{
	NO_MAP = 0,
	PARTIAL_MAP = 1,
	FULL_MAP = 2
};

typedef struct s_img
{
	void		*img_ptr;
	char		*pixel_ptr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_pointf
{
	double		x;
	double		y;
}				t_pointf;

typedef struct s_tex_path
{
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
}				t_tex_path;

typedef struct s_textures
{
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	int			floor;
	int			ceiling;
}				t_textures;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_counter
{
	int			texture_count;
	int			color_count;
	int			map_started;
	int			map_line_index;
}				t_counter;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
}				t_map;

typedef struct s_minimap
{
	enum e_mode	mode;
	int			tile_size;
	int			width_map;
	int			height_map;
	int			width_pix;
	int			height_pix;
	t_point		player_pixel;
	t_pointf	camera;
	t_point		tile_offset;
}				t_minimap;

typedef struct s_player
{
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_keys
{
	int			move_forward;
	int			move_backward;
	int			strafe_left;
	int			strafe_right;
	int			rotate_left;
	int			rotate_right;
	int			pause;
}				t_keys;

typedef struct s_wall
{
	int			map_tile_x;
	int			map_tile_y;
	double		hit_pos_x;
	double		hit_pos_y;
	int			column;
	int			height;
	int			top_y;
	int			bottom_y;
	t_img		*texture;
	int			tex_x;
	int			tex_y;
}				t_wall;

typedef struct s_ray
{
	double		total_dist_x;
	double		total_dist_y;
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	int			hit_side;
	t_wall		wall;
}				t_ray;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_tex_path	tex_path;
	t_textures	textures;
	t_map		map;
	t_player	player;
	t_minimap	minimap;
	t_color		floor_color;
	t_color		ceiling_color;
	t_keys		key_states;
	double		fov;
	double		camera_x[WIDTH];
	double		dist_to_camera_plane;
	t_ray		rays[WIDTH];
	uint64_t	last_frame_time;
	double		dt;
	int			mouse_x;
	int			mouse_y;

}				t_game;

//main.c
void		destroy_display_and_exit(t_game *g, char *msg);
void		init_game(t_game *game);

//init_mlx.c
void		load_texture_to_buffer(t_game *g, t_img *img, char *path, char tex);
void		init_textures(t_game *g);
void		init_hooks(t_game *g);
void		init_mlx(t_game *g);

//init_game.c
void		init_camera(t_game *g);
void		init_minimap(t_game *g);
void		set_player_direction(t_game *g, char direction);
void		init_player(t_game *g);

//events.c
int			close_window(t_game *g);
void		update_key_states(int keycode, t_keys *keys, int toggle);
int			key_handler(int keycode, t_game *g);
int			key_release_handler(int keycode, t_game *g);
int			mouse_move_handler(int x, int y, t_game *g);

//movement.c
t_pointf	get_new_position(t_game *g, double speed, int keycode);
int			is_valid_move(t_game *g, double x, double y);
void		move_player(t_game *g, double speed, int keycode);
void		rotate_player(t_game *g, double rot_speed_radians);
void		handle_events(t_game *g);

//render.c
void		put_pixel(t_img *img, int x, int y, int color);
void		new_img(t_game *vars);
void		draw_ceiling_and_floor(t_game *game);
int			get_tex_pixel(t_img *tex, int x, int y);
int			render_frame(t_game *vars);

//raycasting.c
void		move_to_next_gridline(t_ray *ray, int *map_x, int *map_y);
void		cast_ray(t_game *g, t_ray *ray);
void		calc_ray_direction(t_game *g, t_ray *ray, int column);
void		calc_dda_distances(t_ray *ray, t_player *player);
void		raycasting(t_game *g);

//raycasting2.c
t_img		*get_wall_texture(t_game *g, t_ray *ray);
void		draw_wall_slice(t_game *g, t_wall *wall);
void		calc_wall_height_and_texture(t_game *g, t_ray *ray, int column);

//minimap.c
void		draw_minimap_tile(t_game *g, t_point *pixel, int i, int j);
void		draw_full_map(t_game *g);
void		draw_minimap_view(t_game *g);
void		draw_minimap(t_game *g);

//minimap2.c
void		update_minimap_mode(t_game *g);
void		draw_ray_minimap(t_game *g, t_point p0, t_point p1, int color);
void		raycasting_minimap(t_game *g);
void		draw_player(t_game *g);

//utils.c
uint64_t	get_time_in_ms(void);
int			max(int n1, int n2);
int			iabs(int n);
double		scale_pixel(int unscaled_num, double new_min, double new_max,
				int old_max);

//draw_utils.c
void		draw_line(t_img *img, t_point p0, t_point p1, int color);
void		draw_circle(t_img *img, t_point center, int radius, int color);
t_point		get_last_pixel(t_game *g, t_point *start_pixel);
void		draw_tile(t_game *g, t_point pixel, int color);
void		draw_scaled_texture_tile(t_game *g, t_img *tex_img,
				t_point *start_pixel);

//parser
int			start_parsing(t_game *game, char **argv);
int			handle_line(t_game *game, char *line, t_counter *counter);
int			is_valid_cub_file(char **argv);
int			validate_map(t_game *game);
int			load_cub_file(t_game *game, const char *path);
int			read_cub_lines(t_game *game, int fd, t_counter *counter);
int			parse_single_line(t_game *game, char *line, t_counter *counter);
int			validate_parsing_completion(t_game *game, t_counter *counter);
int			check_valid_chars(t_game *game);
int			check_map_closed(t_game *game);
int			validate_and_store_player(t_game *game);
int			parse_color_line(t_game *game, char *line);
int			handle_map_line(t_game *game, char *line, t_counter *counter);
int			handle_color_line(t_game *game, char *line, t_counter *counter);
int			handle_texture_line(t_game *game, char *line,
				t_counter *counter);
int			append_map_line(t_game *game, char *line, int line_index);
int			parse_texture_line(t_game *game, char *line);
int			ft_error(char *message);
void		destroy_textures(t_game *game);
void		*gnl_free(void *str);
void		free_map(t_game *game);
void		free_rgb_textures(t_game *game, char *rgb_str);
int			invalid_map_line(char *line, int len);
#endif
