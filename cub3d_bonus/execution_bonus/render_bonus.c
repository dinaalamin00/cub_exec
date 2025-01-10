/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:45:45 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 11:30:52 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	draw_ceil(t_cub *cub)
{
	int		i;
	int		j;
	int		height;

	i = 0;
	height = cub->scr_height / 2;
	while (i < height)
	{
		j = 0;
		while (j < cub->scr_width)
		{
			my_mlx_pixel_put(&cub->img, j, i, cub->ceil_color);
			j++;
		}
		i++;
	}
}

static void	draw_floor(t_cub *cub)
{
	int		i;
	int		j;

	i = cub->scr_height / 2;
	while (i < cub->scr_height)
	{
		j = 0;
		while (j < cub->scr_width)
		{
			my_mlx_pixel_put(&cub->img, j, i, cub->floor_color);
			j++;
		}
		i++;
	}
}

void	render_map(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_wind);
	draw_ceil(cub);
	draw_floor(cub);
	ray_cast(cub);
	// draw_minimap(cub);
	if (cub->img.addr == NULL)
		printf("Failed to get image address\n");
	mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
}
