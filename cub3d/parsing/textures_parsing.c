/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:56:17 by sbakhit           #+#    #+#             */
/*   Updated: 2025/01/09 17:08:17 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	trim_and_validate_line(char **map, int i, char *texture_color)
{
	char	*temp;

	temp = ft_strtrim(map[i], " ");
	free(map[i]);
	map[i] = temp;
	if (map[i] && texture_color && (!ft_strncmp(map[i],
				texture_color, ft_strlen(texture_color))))
	{
		if (ft_strncmp(map[i], "C ", 2) && ft_strncmp(map[i], "F ", 2))
			i = file_validation(map, i);
		i = 0;
	}
}

void	texture_parsing(char **map)
{
	static char	*texture_colors[] = {"NO ", "WE ", "SO ", "EA ", "C ", "F "};
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!map || !*map)
		return ;
	while (j < 6)
	{
		while (map[i])
		{
			trim_and_validate_line(map, i, texture_colors[j]);
			if (i == 0)
				break ;
			i++;
		}
		j++;
	}
	if (i != 0)
		print_error(map, 3);
}
