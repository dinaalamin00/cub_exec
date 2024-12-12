# include "cub3d.h"

int events(int keycode, t_cub *cub)
{
    int new_x;
    int new_y;

    new_x = cub->map.player_x;
    new_y = cub->map.player_y;
    if (keycode == ESC)
      exit(0); // should make a function thats clears all , free, and exit
    else if (keycode == W)
	{
      cub->map.player_x += (cos(deg_to_rad(cub->map.player_angle)) * SPEED); // move up
      cub->map.player_y -= (sin(deg_to_rad(cub->map.player_angle))* SPEED); // move up

	}
    else if (keycode == S)
	{
       cub->map.player_x -= cos(deg_to_rad(cub->map.player_angle))* SPEED; // move down
      cub->map.player_y += sin(deg_to_rad(cub->map.player_angle))* SPEED; // move down

	} 
    else if (keycode == D)
	{
       cub->map.player_x += cos((deg_to_rad(cub->map.player_angle + 90))) * SPEED; //move right
      cub->map.player_y += sin((deg_to_rad(cub->map.player_angle + 90))) * SPEED; //move right

	}
    else if (keycode == A)
	{
		cub->map.player_x -= cos(deg_to_rad(cub->map.player_angle + 90)) * SPEED; //move left
		cub->map.player_y -= sin(deg_to_rad(cub->map.player_angle + 90)) * SPEED; //move left

	}
	else if (keycode == ARROW_RIGHT)
	{
		cub->map.player_angle += 5;
		if (cub->map.player_angle >= 360)
			cub->map.player_angle -= 360;
		// new_x += cos(PI/3); //rot right
		// new_y += sin(PI/3); //rot right
	}
	else if (keycode == ARROW_LEFT)
	{
		cub->map.player_angle -= 5;
		if (cub->map.player_angle < 0)
			cub->map.player_angle += 360;
		// new_x -= cos(PI/3) * 100; //rot right
		// new_y -= sin(PI/3) * 100; //rot right
	}
    // if (cub->map.map[new_y][new_x] == '0')
    // {
    //     cub->map.player_x = cub->map.player_x;
    //     cub->map.player_y = cub->map.player_y;
    // }
    render_map(cub);
    return (0);
    
}