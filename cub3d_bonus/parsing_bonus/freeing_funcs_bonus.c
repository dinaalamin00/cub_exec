/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_funcs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:18:31 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_t_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->map_height)
			free(map->map[i++]);
		free(map->map);
	}
	map->map = NULL;
	if (map->north_txt)
		free(map->north_txt);
	if (map->south_txt)
		free(map->south_txt);
	if (map->west_txt)
		free(map->west_txt);
	if (map->east_txt)
		free(map->east_txt);
	map->north_txt = NULL;
	map->south_txt = NULL;
	map->west_txt = NULL;
	map->east_txt = NULL;
	map->map = NULL;
}
