/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entries_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:42:50 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	file_validation(char **map, int i)
{
	int		fd;
	char	*file;
	char	*temp;

	temp = ft_substr(map[i], 3, ft_strlen(map[i]) - 3);
	file = ft_strtrim(temp, " ");
	free(temp);
	if (ft_isdigit(file[0]))
	{
		free(file);
		return (free(file), 0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(file);
		print_error(map, 1);
	}
	return (free(file), close(fd), 0);
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
	if (j > (int)ft_strlen(m_struct->map[i - 1])
		|| j > (int)ft_strlen(m_struct->map[i + 1]))
		print_error(m_struct->map, 3);
	if ((m_struct->map[i - 1][j] != '1' && m_struct->map[i - 1][j] != '0')
	|| (m_struct->map[i + 1][j] != '1' && m_struct->map[i + 1][j] != '0')
	|| (m_struct->map[i][j + 1] != '1' && m_struct->map[i][j + 1] != '0')
	|| (m_struct->map[i][j - 1] != '1' && m_struct->map[i][j - 1] != '0'))
		print_error(m_struct->map, 3);
}

void	zero_surroundings(t_map *m_struct, int i, int j)
{
	if (j > (int)ft_strlen(m_struct->map[i - 1])
		|| j > (int)ft_strlen(m_struct->map[i + 1]))
		print_error(m_struct->map, 3);
	if ((m_struct->map[i - 1][j] != '1' && m_struct->map[i - 1][j] != '0'
		&& m_struct->player_direc &&
			m_struct->map[i - 1][j] != m_struct->player_direc)
	|| (m_struct->map[i + 1][j] != '1' &&
		m_struct->map[i + 1][j] != '0'
		&& m_struct->player_direc &&
			m_struct->map[i + 1][j] != m_struct->player_direc)
	|| (m_struct->map[i][j + 1] != '1' &&
		m_struct->map[i][j + 1] != '0'
		&& m_struct->player_direc &&
			m_struct->map[i][j + 1] != m_struct->player_direc)
	|| (m_struct->map[i][j - 1] != '1' &&
		m_struct->map[i][j - 1] != '0'
		&& m_struct->player_direc &&
			m_struct->map[i][j - 1] != m_struct->player_direc))
		print_error(m_struct->map, 3);
}
