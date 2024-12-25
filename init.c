#include "cub3d.h"

void	set_player(t_map *map)
{
	int	i;
	int	j;

    i = 0;
    map->player_angle = 45;
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

void	set_map(t_map *map)
{
	int		n;
	int		i;
	int		fd;
	char	*line;

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
	map->map = malloc((n + 1) * sizeof (char *));
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
	map->player.hit = NO_HIT;
}

// void    load_text(t_cub *cub, t_texture *text, char *filename)
// {
//     text->img = mlx_xpm_file_to_image(cub->mlx, filename, &text->width, &text->height);
//     if (!text->img)
//     {
//         printf("error in text %s\n", filename);
//         exit (1);
//     }
//     text->addr = mlx_get_data_addr(text->img, &text->bits_per_pixel, &text->line_length, &text->endian);
// }

// void    init_text(t_cub *cub)
// {
//     load_text(cub, &cub->n_text, cub->map.north_txt);
//     load_text(cub, &cub->s_text, cub->map.south_txt);
//     load_text(cub, &cub->e_text, cub->map.east_txt);
//     load_text(cub, &cub->w_text, cub->map.west_txt);
// }