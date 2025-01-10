/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:31:17 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/10 10:18:21 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		if (!file_name_parsing(av[1]))
			pre_program_error_message(1);
		init_all(&cub, av);
		file_parsing(&cub, av);
		if (init_mlx(&cub))
		{
			free_t_map(&cub.map);
			return (1);
		}
		render_map(&cub);
		mlx_hook(cub.mlx_wind, 2, 0, events, &cub);
		mlx_hook(cub.mlx_wind, 17, 0, close_wind, &cub);
		mlx_loop(cub.mlx);
		close_wind(&cub);
	}
	else
		pre_program_error_message(3);
	return (0);
}
