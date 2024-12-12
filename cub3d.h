/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:43 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/12 18:19:02 by diahmed          ###   ########.fr       */
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
# define SPEED 0.1
// # define ARROW_UP 126
// # define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

// # define FOV 60
// # define ROT_SP 0.045
// # define PL_SP 4
#define TILE_SIZE 50
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

// Wall color (gray)
# define WALL_COLOR 0x808080

// Floor color (light gray)
# define FLOOR_COLOR 0xD3D3D3

// Player color (blue)
# define PLAYER_COLOR 0x0000FF

# define RED 0xFF0000



# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "minilibx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map {
	char	**map;
	int		map_height;
	int		map_width;
	// char 	*north_txt;
	// char 	*south_txt ;
	// char 	*west_txt ;
	// char 	*east_txt ;
	int		player_x;
	int		player_y;
	int		player_angle;
	// char	player_direc;
	// int		ceil_color;
	// int		floor_color;
}	t_map;

typedef struct s_cub {
    void    *mlx;
    void    *mlx_wind;
    t_data  img;
    t_map    map;
} t_cub;

void    init_all(t_cub *cub);
void    set_map(t_map *map);
void    set_player(t_map *map);
void    render_map(t_cub *cub);
int 	events(int keycode, t_cub *cub);
float	deg_to_rad(int angle_d);

#endif