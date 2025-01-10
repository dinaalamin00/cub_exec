/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:59:41 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:32 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	get_pixel_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(int *)pixel);
}

static void	slice_wall(t_cub *cub, t_texture *text, int text_x)
{
	double	wall_top;
	double	wall_bottom;
	double	y;
	int		pixel;
	int		text_y;

	wall_top = (cub->scr_height / 2) - wall_height(cub) / 2;
	wall_bottom = (cub->scr_height / 2) + wall_height(cub) / 2;
	y = wall_top;
	if (wall_top < 0)
		y = 0;
	while (y < wall_bottom && y < cub->scr_height)
	{
		text_y = (y - wall_top) * text->height / wall_height(cub);
		pixel = get_pixel_color(text, text_x, text_y);
		my_mlx_pixel_put(&cub->img, cub->map.ray_column, y, pixel);
		y++;
	}
}

static void	render_wall(t_cub *cub)
{
	t_texture	texture;
	double		text_x;

	text_x = 0;
	if (cub->intersect.hit == VERTICAL)
	{
		if (cub->intersect.x < cub->map.player.x)
			texture = cub->e_text;
		else
			texture = cub->w_text;
		text_x = (int)cub->intersect.y % TILE_SIZE;
	}
	else if (cub->intersect.hit == HORIZONTAL)
	{
		if (cub->intersect.y < cub->map.player.y)
			texture = cub->n_text;
		else
			texture = cub->s_text;
		text_x = (int)cub->intersect.x % TILE_SIZE;
	}
	slice_wall(cub, &texture, text_x);
}

void	ray_cast(t_cub *cub)
{
	double	column;
	float	temp;
	double	angle_step;

	column = 0;
	cub->map.ray_angle = cub->map.player_angle + cub->player_fov / 2;
	angle_step = cub->player_fov / cub->scr_width;
	temp = cub->map.player_angle - cub->player_fov / 2;
	reset_angle(&temp);
	while (column < cub->scr_width)
	{
		cub->intersect = intersect_point(&cub->map);
		if (cub->intersect.x != -1 && cub->intersect.y != -1)
		{
			cub->map.ray_column = column;
			render_wall(cub);
		}
		cub->map.ray_angle -= angle_step;
		column++;
	}
}
