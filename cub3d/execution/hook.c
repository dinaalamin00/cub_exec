/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:43:00 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/09 18:55:20 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_wind(t_cub *cub)
{
	destroy(cub);
	exit(0);
}

static void	update_player(t_map map, t_point *player, t_point point)
{
	if (in_range(point, &map))
	{
		if (map.map[(int)(point.y / TILE_SIZE)][(int)(point.x / TILE_SIZE)]
			!= '1')
		{
			player->x = point.x;
			player->y = point.y;
		}
	}
}

void	reset_angle(float *angle)
{
	if ((*angle) < 0)
		*angle += 360;
	else if ((*angle >= (360)))
		*angle -= 360;
}

int	events(int keycode, t_cub *cub)
{
	t_point	new_point;

	new_point = cub->map.player;
	if (keycode == ESC)
		close_wind(cub);
	else if (keycode == W)
		move_front(cub, &new_point);
	else if (keycode == S)
		move_back(cub, &new_point);
	else if (keycode == D)
		move_right(cub, &new_point);
	else if (keycode == A)
		move_left(cub, &new_point);
	else if (keycode == ARROW_RIGHT)
		rotate(&cub->map, -1);
	else if (keycode == ARROW_LEFT)
		rotate(&cub->map, 1);
	update_player(cub->map, &cub->map.player, new_point);
	cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
	cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
	render_map(cub);
	return (0);
}
