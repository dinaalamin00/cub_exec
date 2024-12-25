/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:42:50 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/05 14:42:25 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_validation(char **map, int i)
{
	int	fd;
	char *file;
	char	*temp;
	
	temp = ft_substr(map[i], 3, ft_strlen(map[i]) - 3);
	file = ft_strtrim(temp, " ");
	free(temp);
	if (ft_isdigit(file[0]))
	{
		free(file);
		return ;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		print_error(map, 1);
	}
	free(file);
	close(fd);
}


void	player_angel(t_map *m_struct, int i, int j)
{
	if (m_struct->map[i][j] == 'N')
		m_struct->player_angle = 90;
	else if (m_struct->map[i][j] == 'W')
		m_struct->player_angle = 180;
	else if (m_struct->map[i][j] == 'S')
		m_struct->player_angle = 270;
	else if (m_struct->map[i][j] == 'E')
		m_struct->player_angle = 0;
}

void	player_surroundings(t_map *m_struct, int i, int j)
{
	const int	directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int			walkable_count;
	int			player_x;
	int			player_y;
	int			k;

	k = 0;
	player_x = 0;
	player_y = 0;
	walkable_count = 0;
	while (k < 4)
	{
		player_x = i + directions[k][0];
		player_y = j + directions[k][1];
		if (player_x >= 0 && player_x < m_struct->map_height + 6
			&& player_y >= 0
			&& player_y < (int)ft_strlen(m_struct->map[player_x])
			&& m_struct->map[player_x][player_y] == '0')
			walkable_count++;
		k++;
	}
	if (walkable_count <= 0)
		print_error(m_struct->map, 3);
}
