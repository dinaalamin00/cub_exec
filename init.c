/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:57:49 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/29 15:09:07 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_all(t_cub *cub, char **av)
{
	ft_memset(cub, 0, sizeof (t_cub));
	cub->player_fov = FOV;
	cub->intersect.x = NO_HIT;
	cub->intersect.y = NO_HIT;
	cub->intersect.hit = NO_HIT;
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd == -1)
		pre_program_error_message(2);
}

int	file_name_parsing(const char *map_path)
{
	static char const	*file_format = ".cub";
	int					i;
	int					j;

	i = ft_strlen(map_path) - 1;
	j = 3;
	while (file_format[j] && map_path[i] == file_format[j] && i >= 0)
	{
		i--;
		j--;
		if (j == -1)
			return (1);
	}
	return (0);
}
// void	set_player(t_map *map)
// {
// 	int	i;
// 	int	j;

//     i = 0;
//     map->player_angle = 90;
//     map->ray_angle = map->player_angle;
// 	map->dx = cos(deg_to_rad(map->player_angle));
// 	map->dy = -sin(deg_to_rad(map->player_angle));
// 	while (i < map->map_height && map->map[i])
// 	{
// 		j = 0;
// 		while (j < map->map_width && map->map[i][j])
// 		{
// 			if (map->map[i][j] == 'N')
// 			{
// 				map->map[i][j] = '0';
// 				map->player.x = j * TILE_SIZE + TILE_SIZE / 2;
// 				map->player.y = i * TILE_SIZE + TILE_SIZE / 2;
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	set_map(t_map *map)
// {
// 	int		n;
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	fd = open("map.cub", O_RDONLY);
// 	if (fd == -1)
// 		perror("file");
// 	n = 0;
// 	line = ft_strdup(NULL);
// 	line = get_next_line(fd);
// 	while ((line))
// 	{
// 		n++;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	map->map = malloc((n + 1) * sizeof (char *));
// 	fd = open("map.cub", O_RDONLY);
// 	i = 0;
// 	map->map[i] = get_next_line(fd);
// 	while (map->map[i])
// 	{
// 		i++;
// 		map->map[i] = get_next_line(fd);
// 	}
// 	close (fd);
// 	map->map_height = n;
// 	map->map_width = ft_strlen(map->map[0]);
// 	map->player.hit = NO_HIT;
// }

