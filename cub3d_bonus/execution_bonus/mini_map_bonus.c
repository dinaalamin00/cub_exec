/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:34:19 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 12:01:57 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d_bonus.h"

// void	draw_player(t_cub *cub, double x, double y, int color)
// {
// 	double	i;
// 	double	j;

// 	i = y - TILE_SIZE /(6 * 8);
// 	while (i < y + TILE_SIZE / (6 * 8))
// 	{
// 		j = x - TILE_SIZE / (6 * 8);
// 		while (j < x + TILE_SIZE / (6 * 8))
// 		{
// 			my_mlx_pixel_put(&cub->img, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_mini_tile(t_cub * cub, double x, double y, int color)
{
	double	i;
	double	j;

	i = 0;
	while (i < MINI_TILE_SIZE)
	{
		j = 0;
		while (j< MINI_TILE_SIZE)
		{
			my_mlx_pixel_put(&cub->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

// void	render_2d_map(t_cub *cub)
// {
// 	// double	x;
// 	// double	y;
// 	double	width;
// 	double	height;
// 	// double	tile;
// 	t_point player;
// 	double scr_x;
//     double scr_y;

// 	width = cub->map.map_width * TILE_SIZE / 6;
// 	height = cub->map.map_height * TILE_SIZE / 6;
// 	// x = 0;
// 	// y = cub->map.map_height * TILE_SIZE - height;
// 	player.x = cub->map.player.x / 6;
// 	player.y = cub->map.player.y / 6;
// 	for(int i=0; i < cub->map.map_height; i++)
// 	{
// 		for(int j = 0; j < cub->map.map_width; j++)
// 		{
// 			scr_x = j * TILE_SIZE / 6;
//             scr_y = i * TILE_SIZE / 6;
// 			 if (cub->map.map[i][j] == '1')
//                 draw_tile(cub, scr_x, scr_y, WALL_COLOR); // wall
//             else
//                 draw_tile(cub, scr_x, scr_y, FLOOR_COLOR); //open space

// 		}
// 	}
// 	draw_player(cub, player.x, player.y, PLAYER_COLOR);

// }

// //  double scr_x;
// //     double scr_y;

// //     i = 0;
// //     while (i < cub->map.map_height)
// //     {
// //         j = 0;
// //         while (j < cub->map.map_width)
// //         {
// //             scr_x = j * TILE_SIZE;
// //             scr_y = i * TILE_SIZE;
// //             if (cub->map.map[i][j] == '1')
// //                 draw_tile(&cub->img, scr_x, scr_y, WALL_COLOR); // wall
// //             else
// //                 draw_tile(&cub->img, scr_x, scr_y, FLOOR_COLOR); //open space

// //             j++;
// //         }
// //         i++;
// //     }
// static void	draw_tile(t_cub *cub, double x, double y, int color)
// {
// 	int	i;
// 	int	j;
// 	double	scr_x;
// 	double	scr_y;

// 	i = 0;
// 	scr_x = x *TILE_SIZE;
// 	scr_y = y * TILE_SIZE;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			if ((scr_x + j) >= 0 && ((scr_y + i) >= 0)
// 				&& (((scr_x + j) < cub->minimap_width)
// 					&& ((scr_y + i)) < cub->minimap_height))
// 				my_mlx_pixel_put(&cub->img, scr_x, scr_y, color);
				


// 			j++;
// 		}
// 		i++;
// 	}
// }


// static void draw_line(t_cub *cub, int x1, int y1, int x2, int y2, int color)
// {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (x1 != x2 || y1 != y2)
//     {
//         my_mlx_pixel_put(&cub->img, x1, y1, color);
//         int e2 = err * 2;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }


// void draw_player_direction(t_cub *cub, int scale)
// {
//     int player_x = (cub->map.player.x / TILE_SIZE) * scale;
//     int player_y = (cub->map.player.y / TILE_SIZE) * scale;

//     int line_length = 15; // Length of the direction line
//     int end_x = player_x + cos(cub->map.player_angle) * line_length;
//     int end_y = player_y + sin(cub->map.player_angle) * line_length;

//     draw_line(cub, player_x, player_y, end_x, end_y, PLAYER_COLOR);
// }


// void draw_minimap(t_cub *cub)
// {

//     for (int y = 0; y < cub->map.map_height; y++)
//     {
//         for (int x = 0; cub->map.map[y][x]; x++)
//         {
// 			// printf("::::%s:::\n", cub->map.map[y]);
//             int color = (cub->map.map[y][x] == '1') ? BLACK : GRAY;
//             draw_tile(cub, x * scale, y * scale, color);
//         }
//     }

//     // Draw the player
//     int player_y = (cub->map.player.y / TILE_SIZE) * scale;
//     int player_x = (cub->map.player.x / TILE_SIZE) * scale;
//     draw_tile(cub, player_x, player_y, PLAYER_COLOR);
//     // Draw the player direction
//     draw_player_direction(cub, scale);
// }

void draw_minimap(t_cub *cub)
{
    int start_x, start_y;
    int map_x, map_y;
    int tile_screen_x, tile_screen_y;
    int i, j;
    int color;

    // Bottom-left corner position
    start_x = 10; // Margin from the left edge
    start_y = cub->map.map_height * TILE_SIZE - cub->minimap_height * cub->minimap_tile_size - 10;

    for (i = 0; i < cub->minimap_height; i++)
    {
        for (j = 0; j < cub->minimap_width; j++)
        {
            // Map coordinates
            map_x = (int)(cub->player.x / TILE_SIZE) - cub->minimap_width / 2 + j;
            map_y = (int)(cub->player.y / TILE_SIZE) - cub->minimap_height / 2 + i;

            // Screen coordinates for the tile
            tile_screen_x = start_x + j * cub->minimap_tile_size;
            tile_screen_y = start_y + i * cub->minimap_tile_size;

            // Ensure we are within map bounds
            if (map_x >= 0 && map_x < cub->map.map_width && map_y >= 0 && map_y < cub->map.map_height)
            {
                // Determine tile color
                if (cub->map.map[map_y][map_x] == '1') // Wall
                    color = WALL_COLOR;
                else if (cub->map.map[map_y][map_x] == '0') // Floor
                    color = FLOOR_COLOR;
                else
                    color = BLACK; // Out of bounds or unknown

                // Draw tile
                draw_tile_minimap(cub, tile_screen_x, tile_screen_y, color);
            }
        }
    }

    // Draw the player on the mini-map
    draw_player_minimap(cub, start_x, start_y);
}

void draw_minimap(t_cub *cub)
{
	int	x;
	int	y;
	 int map_x, map_y;
    int tile_screen_x, tile_screen_y;
    int i, j;
    int color;

	x = 10;
	y = cub->scr_height - cub->minimap_height
}
// void draw_minimap(t_cub *cub)
// {
//     int x, y;
//     int mini_map_center_x, mini_map_center_y;
//     int dx, dy;
//     double distance;

//     // Center of the mini-map is the player's position
//     mini_map_center_x = cub->map.player.x * MINI_TILE_SIZE;
//     mini_map_center_y = cub->map.player.y * MINI_TILE_SIZE;

//     for (y = -cub->min_map.radius; y <= cub->min_map.radius; y++)
//     {
//         for (x = -cub->min_map.radius; x <= cub->min_map.radius; x++)
//         {
//             dx = mini_map_center_x + x;
//             dy = mini_map_center_y + y;

//             // Calculate the distance from the center
//             distance = sqrt(x * x + y * y);

//             if (distance <= cub->min_map.radius)
//             {
//                 // Convert mini-map coordinates to map coordinates
//                 int tile_x = (dx / MINI_TILE_SIZE);
//                 int tile_y = (dy / MINI_TILE_SIZE);

//                 // Ensure we're within the map bounds
//                 if (tile_x >= 0 && tile_x < cub->map.map_width &&
//                     tile_y >= 0 && tile_y < cub->map.map_height)
//                 {
//                     // Draw tile
//                     int color = (cub->map.map[tile_y][tile_x] == '1') ? WALL_COLOR : FLOOR_COLOR;
//                     my_mlx_pixel_put(&cub->img, dx, dy, color);
//                 }
//             }
//         }
//     }

//     // Draw player at the center
//     // draw_player_on_minimap(cub, mini_map_center_x, mini_map_center_y);
}

// void draw_player_on_minimap(t_cub *cub, int center_x, int center_y)
// {
//     int player_size = TILE_SIZE / 4; // Smaller size for the player on the mini-map
//     int x, y;

//     for (y = -player_size; y <= player_size; y++)
//     {
//         for (x = -player_size; x <= player_size; x++)
//         {
//             my_mlx_pixel_put(&cub->img, center_x + x, center_y + y, PLAYER_COLOR);
//         }
//     }

//     // Draw direction line
//     double direction_x = cos(cub->player.angle) * player_size * 2;
//     double direction_y = sin(cub->player.angle) * player_size * 2;
//     draw_line(cub, center_x, center_y, center_x + direction_x, center_y + direction_y, PLAYER_COLOR);
// }
