/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:51:51 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/09 16:43:44 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_point	h_intersect(t_map *map, t_point intersect, t_point step)
{
	int	i;
	int	j;

	while (in_range(intersect, map))
	{
		i = (int)(intersect.y / TILE_SIZE);
		j = (int)(intersect.x / TILE_SIZE);
		if (map->map[i][j]
			== '1')
		{
			intersect.hit = HORIZONTAL;
			return (intersect);
		}
		intersect.x += step.x;
		intersect.y += step.y;
	}
	intersect.hit = HORIZONTAL;
	return (intersect);
}

static t_point	horizontal_coord(t_map *map)
{
	t_point	intersect;
	t_point	step;
	t_point	p;
	float	temp;

	temp = map->ray_angle;
	p.x = map->player.x;
	p.y = map->player.y;
	if (map->ray_angle == 0 || map->ray_angle == 180 || map->ray_angle == 360)
		return ((t_point){NO_HIT, NO_HIT, NO_HIT});
	reset_angle(&temp);
	if (temp > 0 && temp < 180)
		intersect.y = floor(map->player.y / TILE_SIZE) * TILE_SIZE - 1;
	else
		intersect.y = floor(map->player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	intersect.x = p.x + (p.y - intersect.y) / tan(deg_to_rad(map->ray_angle));
	step.y = TILE_SIZE;
	if (temp > 0 && temp < 180)
		step.y = -TILE_SIZE;
	step.x = -step.y / tan(deg_to_rad(map->ray_angle));
	return (h_intersect(map, intersect, step));
}

static t_point	v_intersect(t_map *map, t_point intersect, t_point step)
{
	int	i;
	int	j;

	while (in_range(intersect, map))
	{
		i = (int)(intersect.y / TILE_SIZE);
		j = (int)(intersect.x / TILE_SIZE);
		if (map->map[i][j]
			== '1')
		{
			intersect.hit = VERTICAL;
			return (intersect);
		}
		intersect.x += step.x;
		intersect.y += step.y;
	}
	intersect.hit = VERTICAL;
	return (intersect);
}

static t_point	vertical_coord(t_map *map)
{
	t_point	intersect;
	t_point	step;
	t_point	p;
	float	temp;

	if (map->ray_angle == 90 || map->ray_angle == 270)
		return ((t_point){NO_HIT, NO_HIT, NO_HIT});
	temp = map->ray_angle;
	p.x = map->player.x;
	p.y = map->player.y;
	reset_angle(&temp);
	if (temp > 90 && temp < 270)
		intersect.x = floor(map->player.x / TILE_SIZE) * TILE_SIZE - 1;
	else
		intersect.x = floor(map->player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	intersect.y = p.y + (p.x - intersect.x) * tan(deg_to_rad(map->ray_angle));
	step.x = TILE_SIZE;
	if (map->ray_angle > 90 && map->ray_angle < 270)
		step.x = -TILE_SIZE;
	step.y = -step.x * tan(deg_to_rad(map->ray_angle));
	return (v_intersect(map, intersect, step));
}

t_point	intersect_point(t_map *map)
{
	t_point	horizontal_hit;
	t_point	vertical_hit;
	float	h_distance;
	float	v_distance;

	h_distance = -1;
	v_distance = -1;
	horizontal_hit = horizontal_coord(map);
	vertical_hit = vertical_coord(map);
	if (horizontal_hit.x != NO_HIT && horizontal_hit.y != NO_HIT)
		h_distance = count_distance(horizontal_hit, map->player);
	if (vertical_hit.x != NO_HIT && vertical_hit.y != NO_HIT)
		v_distance = count_distance(vertical_hit, map->player);
	if (h_distance < v_distance && v_distance != -1 && h_distance != -1)
		return (horizontal_hit);
	else if (v_distance == -1)
		return (horizontal_hit);
	return (vertical_hit);
}
