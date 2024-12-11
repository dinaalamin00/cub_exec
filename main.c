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
	t_cub cub;

	init_all(&cub);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		return (0);
	cub.mlx_wind = mlx_new_window(cub.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!cub.mlx_wind)
		return (0);
	cub.img.img = mlx_new_image(cub.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub.img.img)
		return (0);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);
	if (!cub.img.addr)
		return (0);

	set_map(&cub.map);
	set_player(&cub.map);

	mlx_key_hook(cub.mlx_wind, key_hook, &cub);
	mlx_hook(cub.mlx_wind, 17, 0, escape, &gmlx);
	mlx_loop(cub.mlx);
	
	
	return 0;
}
