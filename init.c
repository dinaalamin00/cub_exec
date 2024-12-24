# include "cub3d.h"

// void    init_all(t_cub *cub)
// {
//     cub->mlx = NULL;
//     cub->mlx_wind = NULL;
//     cub->img.img = NULL;
//     cub->img.addr = NULL;
//     cub->img.bits_per_pixel= 0;
//     cub->img.line_length = 0;
//     cub->img.endian = 0;
//     cub->map.map = NULL;
//     cub->map.map_height = 0;
//     cub->map.map_width = 0;
//     cub->map.player_x = 0;
//     cub->map.player_y = 0;
// }

void    set_player(t_map *map)
{
    int i;
    int j;

    i = 0;
    map->player_angle = 90;
    map->ray_angle = map->player_angle;
	map->dx = cos(deg_to_rad(map->player_angle));
	map->dy = -sin(deg_to_rad(map->player_angle));
    while (i < map->map_height && map->map[i])
    {
        j = 0;
        while (j < map->map_width && map->map[i][j])
        {
            if (map->map[i][j] == 'N')
            {
                map->map[i][j] = '0';
                map->player.x = j * TILE_SIZE + TILE_SIZE / 2;
                map->player.y = i * TILE_SIZE + TILE_SIZE / 2;
                return ;
            }
            j++;
        }
        i++;
    }
}

void    set_map(t_map *map)
{
    int n;
    int i;
    int fd;
    char * line;

    fd = open("map.cub", O_RDONLY);
    if (fd == -1)
        perror("file");
    n = 0;
    line = ft_strdup(NULL);
    line = get_next_line(fd);
    while ((line))
    {
        n++;
        line = get_next_line(fd);
    }
    close(fd);
    map->map = malloc((n + 1)*sizeof(char *));
    fd = open("map.cub", O_RDONLY);
    i = 0;
    map->map[i] = get_next_line(fd);
    while (map->map[i])
    {
        i++;
        map->map[i] = get_next_line(fd);
    }
    close (fd);
    map->map_height = n;
    map->map_width = ft_strlen(map->map[0]);
	// map->player_fov = 60;
}
