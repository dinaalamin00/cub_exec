/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:43:00 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/24 12:43:21 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Use fmod to constrict the angles to a [0, 360) range. This way,
	you can make sure that it will always be as you want it. Subtracting
	`360` from it doesn't guarantee that it will fall in that range, and
	will force you to hardcode a reset somewhere else in your code!
*/
void reset_angle(double *angle)
{
    *angle = fmod(*angle, 360.0);
    if (*angle < 0)
        *angle += 360.0;
}

int	events(int keycode, t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->map.player.x;
	new_y = cub->map.player.y;
	if (keycode == ESC)
		exit(0); // should make a function thats clears all , free, and exit
	else if (keycode == W)
	{
		new_x += cub->map.dx * SPEED;
		new_y += cub->map.dy * SPEED;
		printf("ang = %f\n\n", cub->map.player_angle);
	}
	else if (keycode == S)
	{
		new_x -= cub->map.dx * SPEED;
		new_y -= cub->map.dy * SPEED;
	}
	else if (keycode == D)
	{
		new_x -= cub->map.dy * SPEED;
		new_y += cub->map.dx * SPEED;
	}
	else if (keycode == A)
	{
		new_x += cub->map.dy * SPEED;
		new_y -= cub->map.dx * SPEED;
	}
	else if (keycode == ARROW_RIGHT)
	{
		cub->map.player_angle -= 3;
		cub->map.ray_angle = cub->map.player_angle;
		reset_angle(&cub->map.player_angle);
		cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
		cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
		printf("ang = %f\n\n", cub->map.player_angle);
	}
	else if (keycode == ARROW_LEFT)
	{
		cub->map.player_angle += 3;
		cub->map.ray_angle = cub->map.player_angle;
		reset_angle(&cub->map.player_angle);
		cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
		cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
		printf("ang = %f\n\n", cub->map.player_angle);
	}
	if (cub->map.map[(int)(new_y / TILE_SIZE)][(int)(new_x / TILE_SIZE)] != '1')
	{
		cub->map.player.x = new_x;
		cub->map.player.y = new_y;
	}
	cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
	cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
	render_map(cub);
	return (0);
}
