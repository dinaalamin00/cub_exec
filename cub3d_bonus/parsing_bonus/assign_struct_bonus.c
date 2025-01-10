/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:43:35 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	textures_assign(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] && i < 6)
	{
		if (!ft_strncmp(map->map[i], "WE ", 3))
			map->west_txt = ft_strtrim(map->map[i], "WE ");
		if (!ft_strncmp(map->map[i], "SO ", 3))
			map->south_txt = ft_strtrim(map->map[i], "SO ");
		if (!ft_strncmp(map->map[i], "NO ", 3))
			map->north_txt = ft_strtrim(map->map[i], "NO ");
		if (!ft_strncmp(map->map[i], "EA ", 3))
			map->east_txt = ft_strtrim(map->map[i], "EA ");
		if (!ft_strncmp(map->map[i], "F ", 2))
			floor_ceiling_colors(map, ft_strtrim(map->map[i], "F "), 0, 0);
		if (!ft_strncmp(map->map[i], "C ", 2))
			floor_ceiling_colors(map, ft_strtrim(map->map[i], "C "), 0, 1);
		i++;
	}
}

static void	map_assign(t_map *m_struct, int file_height)
{
	int		i;
	int		j;
	char	**map;

	i = 6;
	j = 0;
	map = malloc(sizeof(char *) * (file_height - 5));
	if (!map)
	{
		free_t_map(m_struct);
		print_error(m_struct->map, 4);
	}
	m_struct->map_width = ft_strlen(m_struct->map[i]);
	while (m_struct->map[i] && i < file_height)
	{
		map[j] = ft_strdup(m_struct->map[i]);
		if ((int)ft_strlen(m_struct->map[i]) > m_struct->map_width)
			m_struct->map_width = ft_strlen(m_struct->map[i]);
		i++;
		map[j][ft_strlen(map[j]) - 1] = '\0';
		j++;
	}
	map[j] = NULL;
	free_map(m_struct->map);
	m_struct->map = map;
}

static int	color_convert(int *i)
{
	return ((i[0] << 16) | (i[1] << 8) | i[2]);
}

void	assign_struct(t_cub *cub, int file_height)
{
	textures_assign(&cub->map);
	map_assign(&cub->map, file_height);
	cub->floor_color = color_convert(cub->map.floor_color);
	cub->floor_color = color_convert(cub->map.ceil_color);
}
