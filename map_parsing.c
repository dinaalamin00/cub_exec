/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:35 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/05 16:07:54 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_parsing(char **map)
{
	static char	*texture_colors[] = {"NO ", "WE ", "SO ", "EA "};
	int			i;
	int			j;
	char		*temp;

	i = 0;
	j = 0;
	if (!map || !*map)
		return ;
	while (j < 4) // change it if we change the map
	{
		while (map[i])
		{
			temp = ft_strtrim(map[i], " ");
			free(map[i]);
			map[i] = temp;
			if (map[i] && (texture_colors[j] && (!ft_strncmp(map[i], texture_colors[j],
					ft_strlen(texture_colors[j])))))
			{
				file_validation(map, i);
				i = 0;
				break ;
			}
			i++;
		}
		j++;
	}
	if (i != 0)
		print_error(map, 3);
}

void	checking_entries(t_map *m_struct, int i, int j)
{
	if ((m_struct->map[i][j] == 'N' || m_struct->map[i][j] == 'W'
		|| m_struct->map[i][j] == 'S' || m_struct->map[i][j] == 'E')
		&& (j != 0 || m_struct->map[i][j + 1] != '\0'))
	{
		if (m_struct->player_direc != '\0')
			print_error(m_struct->map, 3);
		m_struct->player.x = i;
		m_struct->player.y = j;
		m_struct->player_direc = m_struct->map[i][j];
		player_angel(m_struct, i, j);
		player_surroundings(m_struct, i, j);
	}
	else if (m_struct->map[i][j] != '1' && m_struct->map[i][j] != 32
		&& m_struct->map[i][j + 1] == '\0')
		print_error(m_struct->map, 3);
	else if (m_struct->map[i][j] != '1' && m_struct->map[i][j] != 32
		&& m_struct->map[i][j] != '0')
		print_error(m_struct->map, 3);
	if (m_struct->map[i][j] == 32)
		m_struct->map[i][j] = '0';
}

int	mid_parsing(t_map *m_struct, int map_height)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (m_struct->map[i] && i != map_height - 1)
	{
		j = 1;
		if (m_struct->map[i][0] != '1' && m_struct->map[i][0] != 32)
			print_error(m_struct->map, 3);
		while (m_struct->map[i][j])
		{
			checking_entries(m_struct, i, j);
			j++;
		}
		i++;
	}
	if (m_struct->player_direc == '\0')
		print_error(m_struct->map, 3);
	return (i);
}

void	space_handle(char **map, int i, int j)
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

void	map_entries(t_cub *cub, int map_height)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	cub->map.map_height = map_height - 6;
	if (cub->map.map_height < 3)
		print_error(cub->map.map, 3);
	while (cub->map.map[i][j])
	{
		if (cub->map.map[i][j] != '1' && cub->map.map[i][j] != 32)
			print_error(cub->map.map, 3);
		if (cub->map.map[i][j] == 32)
			cub->map.map[i][j] = '1';
		j++;
	}
	i = mid_parsing(&cub->map, map_height);
	j = 0;
	space_handle(cub->map.map, i, j);
}
