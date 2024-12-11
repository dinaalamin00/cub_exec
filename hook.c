# include "cub3d.h"

int key_hook(int keycode, t_cub *cub)
{
    int new_x;
    int new_y;

    new_x = cub->map.player_x;
    new_y = cub->map.player_y;
    if (keycode == ESC)
		exit(0); // should make a function thats clears all , free, and exit
	else if (keycode == W)
		new_y -= 1; // move up
	else if (keycode == S) 
		new_y += 1; // move down
	else if (keycode == D)
		new_x += 1; //move right
	else if (keycode == A)
		new_x -= 1; //move left
    if (cub->map.map[new_y][new_x] == '0')
    {
        cub->map.player_x = new_x;
        cub->map.player_y = new_y;
    }
    render_map(cub);
    return (0);
    
}