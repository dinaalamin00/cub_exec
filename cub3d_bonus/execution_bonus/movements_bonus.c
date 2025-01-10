/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:44 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:31 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_front(t_cub *cub, t_point *new_point)
{
	new_point->x += cub->map.dx * SPEED;
	new_point->y += cub->map.dy * SPEED;
}

void	move_back(t_cub *cub, t_point *new_point)
{
	new_point->x -= cub->map.dx * SPEED;
	new_point->y -= cub->map.dy * SPEED;
}

void	move_right(t_cub *cub, t_point *new_point)
{
	new_point->x -= cub->map.dy * SPEED;
	new_point->y += cub->map.dx * SPEED;
}

void	move_left(t_cub *cub, t_point *new_point)
{
	new_point->x += cub->map.dy * SPEED;
	new_point->y -= cub->map.dx * SPEED;
}

void	rotate(t_map *map, int direction)
{
	if (direction == -1)
	{
		map->player_angle -= 3;
		map->ray_angle = map->player_angle;
		reset_angle(&map->player_angle);
		map->dx = cos(deg_to_rad(map->player_angle));
		map->dy = -sin(deg_to_rad(map->player_angle));
	}
	else if (direction == 1)
	{
		map->player_angle += 3;
		map->ray_angle = map->player_angle;
		reset_angle(&map->player_angle);
		map->dx = cos(deg_to_rad(map->player_angle));
		map->dy = -sin(deg_to_rad(map->player_angle));
	}
}
