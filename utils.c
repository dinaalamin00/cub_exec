#include "cub3d.h"

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

double  corret_distance(t_cub *cub)
{
    double	distored_d;
	double	correct_d;
	double	ang_diff;

	ang_diff = cub->map.ray_angle - cub->map.player_angle;
	distored_d = distance(cub->intersect, cub->map.player);
	correct_d = distored_d * cos(deg_to_rad(ang_diff));
	return (correct_d);
}

double  wall_height(t_cub *cub)
{
	double	height;
	double	distance_to_screen;
	double	correct_d;

	correct_d = correct_distancce(cub);
	distance_to_screen = WIN_WIDTH / (2 * tan(deg_to_rad(cub->player_fov / 2)));
	height = TILE_SIZE * distance_to_screen / correct_d;
	return (height);
}
