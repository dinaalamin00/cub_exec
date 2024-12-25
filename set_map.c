/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:39:43 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/05 16:16:04 by diahmed          ###   ########.fr       */
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
	if (i > 50)
	{
		printf("You Exceed The Possible Window Height!\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (close(fd), i);
}

// char	**assign_lines(char **map, int fd, int *j)
// {
// 	char	*line;
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	line = NULL;
// 	line = get_next_line(fd);
// 	if (!map || !line)
// 	{
// 		close(fd);
// 		free(line);
// 		print_error(map, 2);
// 	}
// 	while (line != NULL)
// 	{
// 		temp = ft_strtrim(line, " ");
// 		if (ft_strncmp(temp, "", 1))
// 			map[(*j)++] = ft_strdup(line);
// 		free(line);
// 		free(temp);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	return (map);
// }

// char	**file_parsing(t_cub *cub, char **av)
// {
// 	// char	**map;
// 	int		j;

// 	j = 0;
// 	cub->map.map = ft_calloc(sizeof(char *), fd_map_height(cub->fd));
// 	if (!cub->map.map)
// 		pre_program_error_message(4);
// 	cub->fd = open(av[1], O_RDONLY);
// 	if (cub->fd == -1)
// 		print_error(cub->map.map, 1);
// 	cub->map.map = assign_lines(cub->map.map, cub->fd, &j);
// 	texture_parsing(cub->map.map);
// 	map_entries(cub, j);
// 	assign_struct(cub, j);
// 	return (close(cub->fd), cub->map.map);
// }

void	longest_width(int len, int *max)
{
	if (len > *max)
		*max = len;
}

void	assign_lines(t_map *map, int fd, int *j)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	line = NULL;
	line = get_next_line(fd);
	if (!map->map || !line)
	{
		close(fd);
		free(line);
		print_error(map->map, 2);
	}
	while (line != NULL)
	{
		temp = NULL;
		// printf(" %d line : \"%s\"\n",*j+1,  line);

		temp = ft_strtrim(line, " ");
		// printf(" %d line : \"%s\"\ttmep:\"%s\"\n\n",*j+1,  line, temp);
		free(line);
		// if (ft_strncmp(temp, "", 1))
		if (temp)
		{
			map->map[(*j)++] = ft_strdup(temp);
			free(temp);
		}
		i++;
		line = get_next_line(fd);
	}
}

char	**file_parsing(t_cub *cub, char **av)
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
	// for(int i = 0; cub->map.map[i]; i++)
	// {
	// 	printf("%s\n", cub->map.map[i]);
	// 	// free(cub.map.map[i]);
	// }
	
	texture_parsing(cub->map.map);
	map_entries(cub, j);
	assign_struct(cub, j);
	return (close(cub->fd), cub->map.map);
}
