/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:43:35 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/05 14:45:19 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_ceiling_colors(t_map *map, char *trimmed_line, int k)
{
	char	**color;
	int		j;
	int		num;
	char	*trimmed;

	j = 0;
	if (!trimmed_line)
		print_error(map->map, 4);
	color = ft_split(trimmed_line, ',');
	free(trimmed_line);
	if (!color || !color[0] || !color[1] || !color[2] || color[3])
		print_error(map->map, 4);
	while (j < 3)
	{
		trimmed = ft_strtrim(color[j], " ");
		if (!trimmed)
			print_error(map->map, 4);
		free(color[j]);
		color[j] = trimmed;
		num = ft_atoi(color[j]);
		free(trimmed);
		if (num > 255 || num < 0)
			print_error(map->map, 4);
		if (k == 0)
			map->floor_color[j++] = num;
		else if (k == 1)
			map->ceil_color[j++] = num;
	}
	// for (int idx = 0; color[idx] != NULL; idx++)
	// 	free(color[idx]);
	free(color);
}

void	textures_assign(t_map *map)
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
			floor_ceiling_colors(map, ft_strtrim(map->map[i], "CF "), 0);
		if (!ft_strncmp(map->map[i], "C ", 2))
			floor_ceiling_colors(map, ft_strtrim(map->map[i], "CF "), 1);
		i++;
	}
}

void	map_assign(t_map *m_struct, int map_height)
{
	int		i;
	int		j;
	char	**map;

	i = 6;
	j = 0;
	map = malloc(sizeof(char *) * (map_height - 5));
	while (m_struct->map[i] && i < map_height)
	{
		map[j] = ft_strdup(m_struct->map[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	free_map(m_struct->map);
	m_struct->map = map;
}

void	assign_struct(t_cub *cub, int map_height)
{
	textures_assign(&cub->map);
	map_assign(&cub->map, map_height);
}
