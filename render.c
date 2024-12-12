# include "cub3d.h"

float	deg_to_rad(int angle_d)
{
	float	angle_r;

	angle_r = angle_d * (PI/180);
	return (angle_r);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
        exit(0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, int x0, int x1, int y0, int y1, int color)
{
	int	m;
	int	dx;
	int	dy;
	int	temp;
	int	p;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	p = 2 * dx - dy;
	m = dy / dx;
	if (x0 > x1)
	{
		temp = x0;
		x0 = x1;
		x1 = temp;
	}
	// if (y0 >y1)
	// {
	// 	temp = y0;
	// 	y0 = y1;
	// 	y1 = temp;
	// }
	while (x0 <= x1)
	{
		my_mlx_pixel_put(img, x0 , y0 , color);
		x0++;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			y0++;
		}
	}
}

void    draw_tile(t_data *img, int x, int y, int color)
{
    int i;
    int j;

    for (i = 0; i < TILE_SIZE; i++)
    {
        for (j = 0; j< TILE_SIZE; j++)
        {
            my_mlx_pixel_put(img, x + j, y + i, color);
        }
    }
}
void	draw_direction_line(t_data *img, int player_x, int player_y, int angle, int color)
{
	int	x;
	int	y;
	// double dy;
	// double dx;

	// x = player_x + 25;
	// y = player_y + 25;
	// dx = cos(angle);
	// dy = -sin(angle);
	// int i = 0;

	// while (i < 200)
	// {
	// 	my_mlx_pixel_put(img, x, y, color);
	// 	x+= dx;
	// 	y+=dy;
	// 	i++;
	// }
	x = player_x + cos(angle) * 100;
	y = player_y - sin(angle) * 100;
	draw_line(img, player_x + TILE_SIZE / 2, x , player_y , y , color);
}

void    render_map(t_cub *cub)
{
    int i;
    int j;
    int scr_x;
    int scr_y;

    mlx_clear_window(cub->mlx, cub->mlx_wind);
    i = 0;
    while (i < cub->map.map_height)
    {
        j = 0;
        while (j < cub->map.map_width)
        {
            scr_x = j * TILE_SIZE;
            scr_y = i * TILE_SIZE;
            if (cub->map.map[i][j] == '1')
                draw_tile(&cub->img, scr_x, scr_y, WALL_COLOR); // wall
            // else if (cub->map.map[i][j] == 'N')
            //     draw_tile(&cub->img, scr_x, scr_y, FLOOR_COLOR); // player
            else if (cub->map.map[i][j] == '0')
                draw_tile(&cub->img, scr_x, scr_y, FLOOR_COLOR); //open space
            // if (cub->map.map[i][j] == '1')
            //     draw_square(cub, i, j, WALL_COLOR);
            // else if (cub->map.map[i][j] == '0')
            //     draw_square(cub, i, j, FLOOR_COLOR);
            // else if (cub->map.map[i][j] == 'N')
            //     draw_square(cub, i, j, PLAYER_COLOR);

            j++;
        }
        i++;
    }
    draw_tile(&cub->img, cub->map.player_x * TILE_SIZE, cub->map.player_y * TILE_SIZE, RED);
	draw_direction_line(&cub->img, cub->map.player_x * TILE_SIZE, cub->map.player_y * TILE_SIZE, deg_to_rad(cub->map.player_angle), RED);
    if (cub->img.addr == NULL)
        printf("Failed to get image address\n");
    // printf(" player x = %d \t player y = %d\n\n", cub->map.player_x, cub->map.player_y);
    mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
}