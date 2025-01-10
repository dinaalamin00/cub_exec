/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:43 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 11:38:38 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define PI 3.141592653589793238462643383279502884197
# define SPEED 50
# define FOV 60
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define TILE_SIZE 64
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define NO_HIT -1

// Wall color (gray)
# define WALL_COLOR 0x808080

// Floor color (light gray)
# define FLOOR_COLOR 0xD3D3D3

// Player color (blue)
# define PLAYER_COLOR 0x0000FF

# define RED 0xFF0000
# define BLACK 0x000000
# define VERTICAL 1
# define HORIZONTAL 2

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct s_point
{
	float	x;
	float	y;
	int		hit;
}	t_point;

// typedef struct s_keys
// {
// 	int a;
// 	int	w;
// 	int	s;
// 	int	d;
// 	int	left;
// 	int	right;
// }	t_keys;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		map_height;
	int		map_width;
	char	*north_txt;
	char	*south_txt ;
	char	*west_txt ;
	char	*east_txt ;
	t_point	player;
	float	player_angle;
	float	ray_angle;
	float	ray_column;
	float	dx;
	float	dy;
	char	player_direc;
	int		ceil_color[3];
	int		floor_color[3];
	float	scr_width;
	float	scr_height;
}	t_map;

typedef struct s_cub
{
	void		*mlx;
	void		*mlx_wind;
	float		scr_width;
	float		scr_height;
	int			fd;
	t_data		img;
	t_map		map;
	t_texture	n_text;
	t_texture	s_text;
	t_texture	e_text;
	t_texture	w_text;
	t_point		intersect;
	// t_keys		keys;
	int			ceil_color;
	int			floor_color;
	float		player_fov;
}	t_cub;

//exit functions
void	pre_program_error_message(int error_num);
void	print_error(char **map, int error_num);
void	free_map(char **map);
void	free_t_map(t_map *map);
void	destroy(t_cub *cub);
int		close_wind(t_cub *cub);

//parsing functions
int		file_name_parsing(const char *map_path);
void	init_all(t_cub *cub, char **av);
void	file_parsing(t_cub *cub, char **av);
int		fd_map_height(int fd);
void	texture_parsing(char **map);
void	map_entries(t_cub *cub, int file_height, int i);
void	assign_struct(t_cub *cub, int file_height);
int		file_validation(char **map, int i);
void	floor_ceiling_colors(t_map *map, char *trimmed_line, int j, int flag);
void	player_angel(t_map *m_struct, int i, int j);
void	zero_surroundings(t_map *m_struct, int i, int j);
void	player_surroundings(t_map *m_struct, int i, int j);

//exec functions
int		init_mlx(t_cub *cub);
void	init_textures(t_cub *cub);
void	render_map(t_cub *cub);
t_point	intersect_point(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ray_cast(t_cub *cub);
double	count_distance(t_point point, t_point player);
int		in_range(t_point intersect, t_map *map);
double	wall_height(t_cub *cub);
double	deg_to_rad(double angle_d);
void	reset_angle(float *angle);

//moves
int		events(int keycode, t_cub *cub);
void	move_front(t_cub *cub, t_point *new_point);
void	move_back(t_cub *cub, t_point *new_point);
void	move_right(t_cub *cub, t_point *new_point);
void	move_left(t_cub *cub, t_point *new_point);
void	rotate(t_map *map, int direction);

#endif