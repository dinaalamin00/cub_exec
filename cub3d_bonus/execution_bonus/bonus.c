// #include "../cub3D.h"

// void toggle_door(t_cub *cub)
// {
//     int door_x = (int)(cub->map.player_x + cos(cub->map.player_angle) * TILE_SIZE) / TILE_SIZE;
//     int door_y = (int)(cub->map.player_y + sin(cub->map.player_angle) * TILE_SIZE) / TILE_SIZE;

//     if (cub->map.map[door_y][door_x] == 'D')
//         cub->map.map[door_y][door_x] = '0'; // Open the door
//     else if (cub->map.map[door_y][door_x] == '0')
//         cub->map.map[door_y][door_x] = 'D'; // Close the door
// }

// void animate_sprite(t_sprite *sprite)
// {
//     static int frame = 0;

//     sprite->current_image = sprite->images[frame];
//     frame = (frame + 1) % sprite->num_frames;
// }

// void render_sprite(t_cub *cub, t_sprite *sprite)
// {
//     double screen_x = sprite->x - cub->map.player_x;
//     double screen_y = sprite->y - cub->map.player_y;

//     draw_tile(cub, screen_x, screen_y, sprite->current_image);
// }

// int handle_mouse_move(int x, int y, t_cub *cub)
// {
//     static int prev_x = 0;

//     int delta_x = x - prev_x;
//     cub->map.player_angle += delta_x * MOUSE_SENSITIVITY;

//     reset_angle(&cub->map.player_angle); // Keep angle within 0 to 2*PI
//     prev_x = x;
//     return (0);
// }

// void render_map(t_cub *cub)
// {
//     put_background(cub);          // Draw floor and ceiling
//     draw_minimap(cub);            // Display minimap
//     render_sprites(cub);          // Render animated sprites
//     ray_cast(cub);                // Render walls
//     mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
// }
