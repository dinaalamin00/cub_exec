/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:00:55 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 11:25:50 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	load_text(t_cub *cub, t_texture *text, char *filename)
{
	text->img = mlx_xpm_file_to_image(cub->mlx, filename,
			&text->width, &text->height);
	if (!text->img)
	{
		printf("error in text %s\n", filename);
		destroy(cub);
		exit (EXIT_FAILURE);
	}
	text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_length, &text->endian);
	if (!text->addr)
	{
		destroy(cub);
		exit (EXIT_FAILURE);
	}
}

void	init_textures(t_cub *cub)
{
	load_text(cub, &cub->n_text, cub->map.north_txt);
	load_text(cub, &cub->s_text, cub->map.south_txt);
	load_text(cub, &cub->e_text, cub->map.east_txt);
	load_text(cub, &cub->w_text, cub->map.west_txt);
}

int	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->scr_height = WIN_HEIGHT;
	cub->scr_width = WIN_WIDTH;
	// cub->minimap_height = cub->scr_height / 6;
	// cub->minimap_width = cub->scr_width / 6;
	cub->min_map.radius = 3 * MINI_TILE_SIZE;
	cub->mlx_wind = mlx_new_window(cub->mlx, cub->scr_width,
			cub->scr_height, "cub3D");
	if (!cub->mlx_wind)
		return (free(cub->mlx), 1);
	cub->img.img = mlx_new_image(cub->mlx, cub->scr_width,
			cub->scr_height);
	if (!cub->img.img)
	{
		mlx_destroy_window(cub->mlx, cub->mlx_wind);
		free(cub->mlx);
		return (1);
	}
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	if (!cub->img.addr)
		close_wind(cub);
	init_textures(cub);
	return (0);
}
