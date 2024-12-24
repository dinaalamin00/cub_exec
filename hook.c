# include "cub3d.h"

void	reset_angle(double *angle)
{
	if ((*angle) < 0)
			*angle += 360;
	else if ((*angle >= (360)))
			*angle -= 360;
}
int events(int keycode, t_cub *cub)
{
    double new_x;
    double new_y;
	// float	dx;
	// float	dy;

    new_x = cub->map.player.x;
    new_y = cub->map.player.y;

    if (keycode == ESC)
      exit(0); // should make a function thats clears all , free, and exit
    else if (keycode == W)
	{
     	new_x += cub->map.dx * SPEED; // move up
     	new_y += cub->map.dy * SPEED; // move up
		printf("ang = %f\n\n", cub->map.player_angle);
	// in a 2d map only y changes
	}
    else if (keycode == S)
	{
		new_x -= cub->map.dx * SPEED;
		new_y -= cub->map.dy * SPEED;
    //   new_y += 1; // move down
	// in a 2d map only y changes

	} 
    else if (keycode == D)
	{
		new_x -= cub->map.dy * SPEED; //move right
	   new_y += cub->map.dx * SPEED;
	// in a 2d map only x changes
	}
    else if (keycode == A)
	{
		new_x += cub->map.dy * SPEED; //move left
		new_y -= cub->map.dx * SPEED;
		// new_y -= 1; //move left
	// in a 2d map only x changes

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
	// reset_angle(&cub->map.player_angle);
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
