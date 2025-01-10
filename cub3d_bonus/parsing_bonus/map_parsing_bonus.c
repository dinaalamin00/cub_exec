/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:35 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	checking_entries(t_map *m_struct, int i, int j)
{
	if ((m_struct->map[i][j] == 'N' || m_struct->map[i][j] == 'W'
		|| m_struct->map[i][j] == 'S' || m_struct->map[i][j] == 'E')
		&& (j != 0 || m_struct->map[i][j + 1] != '\0'))
	{
		if (m_struct->player_direc != '\0')
			print_error(m_struct->map, 3);
		m_struct->player.x = j * TILE_SIZE;
		m_struct->player.y = (i - 6) * TILE_SIZE;
		m_struct->player_direc = m_struct->map[i][j];
		player_angel(m_struct, i, j);
		player_surroundings(m_struct, i, j);
	}
	else if (m_struct->map[i][j] != '1' && m_struct->map[i][j + 1] == '\0')
		print_error(m_struct->map, 3);
	else if (m_struct->map[i][j] != '1' && m_struct->map[i][j] != '0')
		print_error(m_struct->map, 3);
	if (m_struct->map[i][j] == '0')
		zero_surroundings(m_struct, i, j);
}

static void	mid_parsing(t_map *m_struct, int file_height)
{
	int	i;
	int	j;

	i = 7;
	while (m_struct->map[i] && i < file_height - 1)
	{
		j = 1;
		if (m_struct->map[i][0] != '1')
			print_error(m_struct->map, 3);
		while (m_struct->map[i][j])
			checking_entries(m_struct, i, j++);
		i++;
	}
	if (m_struct->player_direc == '\0')
		print_error(m_struct->map, 3);
}

static void	space_handle(t_cub *cub, int i, int j)
{
	while (cub->map.map[i][j])
	{
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != 32)
			print_error(cub->map.map, 3);
		if (cub->map.map[i][j] == 32)
			cub->map.map[i][j] = '1';
		j++;
	}
}

static void	check_and_replace_space(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != 32)
			print_error(map, 3);
		if (map[i][j] == 32)
			map[i][j] = '1';
		j++;
	}
}

void	map_entries(t_cub *cub, int file_height, int i)
{
	int	j;

	cub->map.map_height = file_height - 6;
	if (cub->map.map_height < 3)
		print_error(cub->map.map, 3);
	j = 0;
	check_and_replace_space(cub->map.map, i, j);
	while (++i < file_height - 1)
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 32)
			{
				if (j == 0 || cub->map.map[i][j + 1] == '\0')
					cub->map.map[i][j] = '1';
				else
					cub->map.map[i][j] = '0';
			}
			j++;
		}
	}
	space_handle(cub, i, 0);
	mid_parsing(&cub->map, file_height);
}
