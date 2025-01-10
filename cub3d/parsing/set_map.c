/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:39:43 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/09 18:39:38 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	fd_map_height(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && i == 0)
		{
			close(fd);
			exit(EXIT_FAILURE);
		}
		if (!line)
			break ;
		i++;
		free(line);
	}
	return (close(fd), i);
}

void	longest_width(int len, int *max)
{
	if (len > *max)
		*max = len;
}

static void	assign_lines(t_map *map, int fd, int *j)
{
	char	*line;
	char	*temp;

	line = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free(line);
		print_error(map->map, 2);
	}
	while (line != NULL)
	{
		temp = NULL;
		temp = ft_strtrim(line, "\n");
		if (temp)
		{
			map->map[(*j)++] = ft_strdup(temp);
			free(temp);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	file_parsing(t_cub *cub, char **av)
{
	int		j;

	j = 0;
	cub->map.map = ft_calloc(sizeof(char *), fd_map_height(cub->fd) + 1);
	if (!cub->map.map)
		pre_program_error_message(4);
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd == -1)
		print_error(cub->map.map, 1);
	assign_lines(&cub->map, cub->fd, &j);
	close(cub->fd);
	texture_parsing(cub->map.map);
	map_entries(cub, j, 6);
	assign_struct(cub, j);
	return ;
}
