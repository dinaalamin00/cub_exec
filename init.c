# include "cub3d.h"

void    init_all(t_cub *cub)
{
    cub->mlx = NULL;
    cub->mlx_wind = NULL;
    cub->img.img = NULL;
    cub->img.addr = NULL;
    cub->img.bits_per_pixel= 0;
    cub->img.line_length = 0;
    cub->img.endian = 0;
    cub->map.map = NULL;
    cub->map.map_height = 0;
    cub->map.map_width = 0;
    cub->map.player_x = 0;
    cub->map.player_y = 0;
}

void    set_player(t_map *map)
{
    int i;
    int j;

    for (i = 0; i < map->map_height; i++)
    {
        for (j = 0; j < map->map_width; j++)
        {
            if (map->map[i][j] == 'N')
            {
                map->player_x = j;
                map->player_y = i;
                map->map[i][j] = '0';
                return ;
            }

        }
    }  
}

void    set_map(t_map *map)
{
    map->map = {
    "111111",
    "100101",
    "101001",
    "1100N1",
    "111111",
    };
    map->map_height = 6;
    map->map_width = 5;
}
