/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:31:17 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/10 15:48:36 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

	// char *txt_n ;
	// char *txt_s ;
	// char *txt_w ;
	// char *txt_e ;
	// int	p_pos_x;
	// int	p_pos_y;
	// int	c_col;
	// int	f_col;
	// char **map;
	
typedef struct t_map {
	char	**map;
	int		map_height;
	int		map_width;
	char 	*north_txt;
	char 	*south_txt ;
	char 	*west_txt ;
	char 	*east_txt ;
	int		player_pos_x;
	int		player_pos_y;
	char	player_direc;
	int		ceil_color;
	int		floor_color;
}	s_map;
	
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_data *img, int x1, int y1, int x2, int y2, int color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(img, x1, y1, color);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}

int main(void)
{
	void *mlx;
	void*mlx_wind;
	t_data img;
	char *path;
	int	x;
	int	y;
	// int color;
	int	offset;
	
	x = 1;
	y = 1;
	// int		img_w;
	// int		img_h;

	path = "/Users/diahmed/Desktop/cub/tiles/background.xpm";
	
	mlx = mlx_init();
	mlx_wind = mlx_new_window(mlx, 1920, 1080, "cub3d");
	img.img = mlx_new_image(mlx, 1920, 1080);
	if (!img.img)
		return (0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	offset = y * img.line_length + x * (img.bits_per_pixel / 8);
	// color = ((x * 153 / 1920) << 16) | ((y * 153 / 1080) << 8);
	// for(x = 0; x < 200; x++)
	// {
	// 	my_mlx_pixel_put(&img, 100, x, 0x00660033);
	// }  
	draw_line(&img, 100, 100, 400, 400, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_wind, img.img, 0, 0);
	mlx_loop(mlx);
	
	
	return 0;
}
