/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:24:45 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*assign_map(char **map, char *line, int *i)
{
	map[*i] = ft_calloc(sizeof(char), (ft_strlen(line) + 1));
	if (!map[*i])
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	ft_strlcpy(map[*i], line, (ft_strlen(line) + 1));
	free(line);
	return (map[(*i)]);
}

char	**map_parsing(int fd, char **av)
{
	char	*line;
	char	**map;
	int		i;

	line = NULL;
	i = 0;
	map = ft_calloc(sizeof(char *), fd_map_height(fd) + 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_error(map, 1);
	line = get_next_line(fd);
	if (!map || !line)
	{
		close(fd);
		print_error(map, 2);
	}
	while (line != NULL)
	{
		map[i] = assign_map(map, line, &i);
		i++;
		line = get_next_line(fd);
	}
	return (close(fd), map);
}
