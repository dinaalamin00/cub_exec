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

    // for(int i =0; map->map[i]; i++)
    //     printf("%s\n", map->map[i]);
    printf(" hi = %d \t we = %d\n\n", map->map_height, map->map_width);

    i = 0;
    while (i < map->map_height && map->map[i])
    {
        j = 0;
        while (j < map->map_width && map->map[i][j])
        {
            if (map->map[i][j] == 'N')
            {

                map->player_x = i;
                map->player_y = j;
                map->map[i][j] = '0';
                return ;
            }
            j++;
        }
        i++;
    }
        printf(" player x = %d \t player y = %d\n\n", map->player_x, map->player_y);

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
    // for(int i =0; map->map[i]; i++)
    //     printf("%s\n", map->map[i]);
    map->map_height = n;
    map->map_width = ft_strlen(map->map[0]);
}
