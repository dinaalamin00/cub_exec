/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:38:43 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/09 20:35:40 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
// # define ARROW_UP 126
// # define ARROW_DOWN 125
// # define ARROW_LEFT 123
// # define ARROW_RIGHT 124

// # define FOV 60
// # define ROT_SP 0.045
// # define PL_SP 4
#define TILE_SIZE 50
#define WIN_WIDTH 300
#define WIN_HEIGHT 250


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
int key_hook(int keycode, t_cub *cub);
#endif