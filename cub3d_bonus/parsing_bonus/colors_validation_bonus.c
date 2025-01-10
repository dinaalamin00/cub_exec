/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_validation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:26:03 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	validate_color_string(t_map *map, char *trimmed_line)
{
	int	i;
	int	comma_counter;

	i = 0;
	comma_counter = 0;
	if (!trimmed_line || !ft_isdigit(trimmed_line[i++]))
	{
		free(trimmed_line);
		free_t_map(map);
		print_error(map->map, 3);
	}
	while (trimmed_line[i] && i < (int)ft_strlen(trimmed_line))
	{
		if ((trimmed_line[i] != ',' || (trimmed_line[i] == ','
					&& comma_counter >= 2))
			&& !ft_isdigit(trimmed_line[i]) && trimmed_line[i] != 32)
		{
			free(trimmed_line);
			free_t_map(map);
			print_error(map->map, 3);
		}
		if (trimmed_line[i] == ',')
			comma_counter++;
		i++;
	}
}

char	**assign_color(t_map *map, char *trimmed_line, char **color)
{
	color = ft_split(trimmed_line, ',');
	free(trimmed_line);
	if (!color || !color[0] || !color[1] || !color[2] || color[3])
	{
		free_t_map(map);
		print_error(map->map, 4);
	}
	return (color);
}

static int	color_num(t_map *map, char **color, int j)
{
	char	*trimmed;
	int		num;

	trimmed = ft_strtrim(color[j], " ");
	if (!trimmed)
	{
		free_t_map(map);
		free_map(color);
		print_error(map->map, 4);
	}
	num = ft_atoi(trimmed);
	free(trimmed);
	return (num);
}

void	floor_ceiling_colors(t_map *map, char *trimmed_line, int j, int flag)
{
	char	**color;
	int		num;

	color = NULL;
	validate_color_string(map, trimmed_line);
	color = assign_color(map, trimmed_line, color);
	while (j < 3)
	{
		num = color_num(map, color, j);
		free(color[j]);
		if (num > 255 || num < 0)
		{
			free_map(color);
			free_t_map(map);
			print_error(map->map, 4);
		}
		if (flag == 0)
			map->floor_color[j++] = num;
		else if (flag == 1)
			map->ceil_color[j++] = num;
	}
	free(color);
}
