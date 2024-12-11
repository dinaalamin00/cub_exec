# include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    // if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
    //     exit(0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_tile(t_data *img, int x, int y, int color)
{
    int i;
    int j;

    for (i = 0; i < y; i++)
    {
        for (j = 0; j< x; j++)
        {
            my_mlx_pixel_put(img, x + j, y + i, color);
        }
    }
}
void draw_square(t_cub *cub, int x, int y, int color) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            my_mlx_pixel_put(&cub->img, x * 10 + i, y * 10 + j, color);
        }
    }
}

void    render_map(t_cub *cub)
{
    int i;
    int j;
    int scr_x;
    int scr_y;

    mlx_clear_window(cub->mlx, cub->mlx_wind);
    i = 0;
    while (cub->map.map[i])
    {
        j = 0;
        while (cub->map.map[i][j])
        {
            scr_x = j * TILE_SIZE;
            scr_y = i * TILE_SIZE;
            if (cub->map.map[i][j] == '1')
                draw_tile(&cub->img, scr_x, scr_y, 0x00ff00); // wall
            else
                draw_tile(&cub->img, scr_x, scr_y, 0x000000); //open space
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
    draw_tile(&cub->img, cub->map.player_x * TILE_SIZE, cub->map.player_y * TILE_SIZE, 0xFF0000);
    if (cub->img.addr == NULL)
        printf("Failed to get image address\n");

    mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
}
