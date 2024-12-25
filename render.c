/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:45:45 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/25 16:11:40 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double angle_d)
{
	double	angle_r;

	// reset_angle(&angle_d);
	if ((angle_d) < 0)
		angle_d += 360;
	else if ((angle_d > (360)))
		angle_d -= 360;
	angle_r = angle_d * (PI / 180.0);
	return (angle_r);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, t_cub *cub)
{
	char	*dst;

	if ((x < 0 || y < 0) || (x >= cub->map.map_width * TILE_SIZE || y >= cub->map.map_height * TILE_SIZE))
		exit(0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	draw_player(t_data *img, double x, double y, int color)
// {
// 	double	i;
// 	double	j;

// 	i = y - TILE_SIZE / 8;
// 	while (i < y + TILE_SIZE / 8)
// 	{
// 		j = x - TILE_SIZE / 8;
// 		while (j < x + TILE_SIZE / 8)
// 		{
// 			my_mlx_pixel_put(img, j, i, color, cub);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_tile(t_data *img, double x, double y, int color)
// {
// 	double	i;
// 	double	j;

// 	i = 0;
// 	while (i + 1 < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j + 1 < TILE_SIZE)
// 		{
// 			my_mlx_pixel_put(img, x + j, y + i, color, cub);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_floor(t_data *img, double x, double y, int color, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			my_mlx_pixel_put(img, x + j, y + i, color, cub);
			j++;
		}
		i++;
	}
}

// void	draw_ray(t_cub *cub, t_point intersect)
// {
// 	double	x;
// 	double	y;
// 	double	distance;

// 	x = cub->map.player.x;
// 	y = cub->map.player.y;
// 	distance = count_distance(intersect, (t_point){x, y});
// 	while (distance-- > 0)
// 	{
// 		my_mlx_pixel_put(&cub->img, x, y, RED);
// 		x += cos(deg_to_rad(cub->map.ray_angle));
// 		y -= sin(deg_to_rad(cub->map.ray_angle));
// 	}
// }


void	ray_cast(t_cub *cub)
{
	double	column;
	double	temp;

	column = 0;
	cub->map.ray_angle = cub->map.player_angle + cub->player_fov / 2;
	// reset_angle(&cub->map.player_angle);
	// while (cub->map.ray_angle < (cub->map.player_angle + cub->player_fov / 2))
	// {
	// 	cub->intersect = intersect_point(&cub->map);
	// 	if (cub->intersect.x != -1 && cub->intersect.y != -1)
	// 	{
	// 		cub->map.ray_column = column;
	// 		render_wall(cub);
	// 	}
	// 	cub->map.ray_angle += 0.1;
	// 	column++;
	// }
	// cub->map.ray_angle = cub->map.player_angle;
	// column = TILE_SIZE * cub->map.map_width - 1;
	temp = cub->map.player_angle - cub->player_fov / 2;
	reset_angle(&temp);
	while (cub->map.ray_angle > temp)
	{
		cub->intersect = intersect_point(&cub->map);
		if (cub->intersect.x != -1 && cub->intersect.y != -1)
		{
			cub->map.ray_column = column;
			render_wall(cub);
		}
		cub->map.ray_angle -= 0.1;
		printf("column ::: %f\n\n", column);
		column++;
		// reset_angle(&cub->map.ray_angle);
	}
}

void	put_black_floor(t_cub *cub)
{
	int		i;
	int		j;
	double	scr_x;
	double	scr_y;

	mlx_clear_window(cub->mlx, cub->mlx_wind);
	i = 0;
	while (i < cub->map.map_height)
	{
		j = 0;
		while (j < cub->map.map_width)
		{
			scr_x = j * TILE_SIZE;
			scr_y = i * TILE_SIZE;
			draw_floor(&cub->img, scr_x, scr_y, BLACK, cub); // wall
			j++;
		}
		i++;
	}
}

void	draw_ceil_floor(t_cub *cub, double color)
{
	int i;
    int j;
	int	height;
    double scr_x;
    double scr_y;

    // mlx_clear_window(cub->mlx, cub->mlx_wind);
    i = 0;
	if (color == FLOOR_COLOR)
		i = cub->map.map_height / 2;
	height = (i + cub->map.map_height) / 2;
	if (color == FLOOR_COLOR)
		height = cub->map.map_height;
    while (i < height)
    {
        j = 0;
        while (j < cub->map.map_width)
        {
            scr_x = j * TILE_SIZE;
            scr_y = i * TILE_SIZE;
            draw_floor(&cub->img, scr_x, scr_y, color, cub); // wall
            j++;
        }
        i++;
    }
}

void	render_map(t_cub *cub)
{
	int		i;
	int		j;
	double	scr_x;
	double	scr_y;

	i = 0;
	put_black_floor(cub);
	draw_ceil_floor(cub, FLOOR_COLOR);
	draw_ceil_floor(cub, PLAYER_COLOR);
	ray_cast(cub);
	if (cub->img.addr == NULL)
		printf("Failed to get image address\n");
	mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
}
