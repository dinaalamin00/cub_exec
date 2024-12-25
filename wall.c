#include "cub3d.h"
/* 
- load textures
- in the interset point return the type of intersection if its vertical or horizontal
- checking the type of intersection flag to determine the textures to be used, vertical::east/west, horizontal::north/south
- to decide which one of the two textures after knowing the intersection type;
    for vertial intersection check intersect.x, for horizontal check intersect.y
-
*/

int get_pixel_color(t_texture *tex, int x, int y)
{
    char *pixel = tex->data + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
    return *(int *)pixel;
}


void    slice_wall(t_cub *cub, t_texture *text, int text_x)
{
    double  wall_top;
    double  wall_bottom;
    double  y;
    double  pixel;
    int     text_y;

    wall_top = WIN_HEIGHT / 2 - wall_height(cub) / 2;
    wall_bottom = WIN_HEIGHT / 2 + wall_height(cub) / 2;
    y = wall_top;
    if (wall_top < 0)
        y = 0; // if top < 0 :: top = 0
    while (y < wall_bottom && y < WIN_HEIGHT)
    {
        text_y = (y - wall_top) * text->height / wall_height();
        pixel = get_pixel_color(text, text_x, text_y);
        my_mlx_pixel_put(cub->img, cub->map.ray_column, y, pixel);
        y++;
    }
    
}
void    render_wall(t_cub *cub)
{
    t_texture   texture;
    int         text_x;
    // int         text_y;

    if (cub->intersect.hit == VERTICAL)
    {
        if (cub->intersect.x < cub->map.player.x)
            texture = cub->e_text;
        else
            texture = cub->w_text;
        text_x = (int)cub->intersect.x % TILE_SIZE;
    }
    else if (cub->intersect.hit == HORIZONTAL)
    {
        if (cub->intersect.y < cub->map.player.y)
            texture = cub->n_text;
        else
            texture = cub->s_text;
        text_x = (int)cub->intersect.y % TILE_SIZE;

    }
    slice_wall(cub, &texture, text_x);
}

// void render_walls(t_cub *cub)
// {
//     double ray_angle = cub->map.player_angle - cub->player_fov / 2;
//     double angle_step = cub->player_fov / WIN_WIDTH;
//     int column = 0;

//     while (column < WIN_WIDTH)
//     {
//         reset_angle(&ray_angle);

//         t_point intersect = intersect_point(&cub->map);
//         if (intersect.x == NO_HIT || intersect.y == NO_HIT)
//         {
//             ray_angle += angle_step;
//             column++;
//             continue;
//         }

//         int is_vertical = (intersect.type == VERTICAL);
//         t_texture *texture = is_vertical
//                                  ? (intersect.x > cub->map.player.x ? &cub->tex.east : &cub->tex.west)
//                                  : (intersect.y > cub->map.player.y ? &cub->tex.south : &cub->tex.north);

//         int texture_x = is_vertical
//                             ? (int)intersect.y % TILE_SIZE
//                             : (int)intersect.x % TILE_SIZE;

//         double distance = count_distance(intersect, cub->map.player);
//         double corrected_distance = distance * cos(deg_to_rad(ray_angle - cub->map.player_angle));
//         double wall_height = (TILE_SIZE * WIN_HEIGHT) / corrected_distance;

//         int top = (WIN_HEIGHT / 2) - (wall_height / 2);
//         int bottom = (WIN_HEIGHT / 2) + (wall_height / 2);

//         int y = top < 0 ? 0 : top;
//         while (y < bottom && y < WIN_HEIGHT)
//         {
//             int texture_y = ((y - top) * texture->height) / wall_height;
//             int color = get_pixel_color(texture, texture_x, texture_y);
//             my_mlx_pixel_put(&cub->img, column, y, color);
//             y++;
//         }

//         ray_angle += angle_step;
//         column++;
//     }
//     mlx_put_image_to_window(cub->mlx, cub->mlx_wind, cub->img.img, 0, 0);
// }
