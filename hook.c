# include "cub3d.h"

int events(int keycode, t_cub *cub)
{
    double new_x;
    double new_y;
	// float	dx;
	// float	dy;

    new_x = cub->map.player_x;
    new_y = cub->map.player_y;

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
		cub->map.player_angle -= 45;
		cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
		cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
		printf("ang = %f\n\n", cub->map.player_angle);
	}
	else if (keycode == ARROW_LEFT)
	{
		cub->map.player_angle += 45;
		cub->map.dx = cos(deg_to_rad(cub->map.player_angle));
		cub->map.dy = -sin(deg_to_rad(cub->map.player_angle));
		printf("ang = %f\n\n", cub->map.player_angle);
	}
	if ((cub->map.player_angle) < 0)
			cub->map.player_angle += 360;
	else if ((cub->map.player_angle >= (360)))
			cub->map.player_angle -= 360;
    if (cub->map.map[(int)(new_y)][(int)new_x] == '0')
    {
        cub->map.player_x = new_x;
        cub->map.player_y = new_y;
    }
    render_map(cub);
    return (0);
    
}
