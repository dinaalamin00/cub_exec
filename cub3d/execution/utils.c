/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:41:17 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 16:48:19 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
- height of the wall slice.
	wall_height = TILE_SIZE × distance_to_screen / correct_distance
	Where distance_to_screen is a constant based on the screen size and FOV:
	distance_to_screen = WIN_WIDTH / (2 × tan⁡(FOV / 2))
- Loop Through Rays:
	For each ray, calculate its intersection with walls.
	Normalize the distances using a fisheye correction to avoid distortion:
	corrected_distance = distance_to_wall * cos(ray_angle − player_angle)
 
- Render Wall Slice:
	Use the  wall_height to draw a vertical line in the screen's center.
	top of the line(wall): 
		top = WIN_HEIGHT / 2 − wall_height / 2 
	bottom of the line(wall):
		bottom = WIN_HEIGHT / 2 + wall_height / 2
*/

double	correct_distance(t_cub *cub)
{
	double	distored_d;
	double	correct_d;
	double	ang_diff;

	ang_diff = cub->map.ray_angle - cub->map.player_angle;
	distored_d = count_distance(cub->intersect, cub->map.player);
	correct_d = distored_d * cos(deg_to_rad(ang_diff));
	return (correct_d);
}

double	wall_height(t_cub *cub)
{
	double	height;
	double	distance_to_screen;
	double	correct_d;

	correct_d = correct_distance(cub);
	distance_to_screen = cub->scr_width
		/ (4 * tan(deg_to_rad(cub->player_fov / 2)));
	height = TILE_SIZE * distance_to_screen / correct_d;
	return (height);
}

double	deg_to_rad(double angle_d)
{
	double	angle_r;

	if ((angle_d) < 0)
		angle_d += 360;
	else if ((angle_d > (360)))
		angle_d -= 360;
	angle_r = angle_d * (PI / 180.0);
	return (angle_r);
}

double	count_distance(t_point point, t_point player)
{
	double	distance;

	distance = sqrt(pow(player.x - point.x, 2) + pow(player.y - point.y, 2));
	return (distance);
}

int	in_range(t_point intersect, t_map *map)
{
	if (intersect.y >= 0 && intersect.x >= 0
		&& (int)(intersect.y / TILE_SIZE) < map->map_height
		&& (int)(intersect.x / TILE_SIZE)
		< (int)ft_strlen(map->map[(int)(intersect.y / TILE_SIZE)]))
		return (1);
	return (0);
}
