/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:57:49 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 10:16:53 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_all(t_cub *cub, char **av)
{
	ft_memset(cub, 0, sizeof (t_cub));
	cub->player_fov = FOV;
	cub->intersect.x = NO_HIT;
	cub->intersect.y = NO_HIT;
	cub->intersect.hit = NO_HIT;
	cub->scr_height = -1;
	cub->scr_width = -1;
	cub->fd = open(av[1], O_RDONLY);
	if (cub->fd == -1)
		pre_program_error_message(2);
}

int	file_name_parsing(const char *map_path)
{
	static char const	*file_format = ".cub";
	int					i;
	int					j;

	i = ft_strlen(map_path) - 1;
	j = 3;
	while (file_format[j] && map_path[i] == file_format[j] && i >= 0)
	{
		i--;
		j--;
		if (j == -1)
			return (1);
	}
	return (0);
}
