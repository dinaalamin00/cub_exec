/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:21:13 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/09 18:48:02 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !(*map))
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	pre_program_error_message(int error_num)
{
	if (error_num == 1)
		printf("Error! Wrong File.\n");
	if (error_num == 2)
		printf("Error! Can't Open File.\n");
	if (error_num == 3)
		printf("Error! Wrong Num of Args.\n");
	if (error_num == 4)
		printf("Error! Allocation Failed.\n");
	exit(EXIT_FAILURE);
}

void	print_error(char **map, int error_num)
{
	if (error_num == 1)
		printf("Error! Can't Open File.\n");
	if (error_num == 2)
		printf("Error! Map is Empty.\n");
	if (error_num == 3)
		printf("Error! Invalid Map Entries.\n");
	if (error_num == 4)
		printf("Error! Invalid RGB Entries.\n");
	if (map)
		free_map(map);
	exit(EXIT_FAILURE);
}

void	destroy(t_cub *cub)
{
	free_t_map(&cub->map);
	if (cub->img.img)
		mlx_destroy_image(cub->mlx, cub->img.img);
	if (cub->mlx_wind)
		mlx_destroy_window(cub->mlx, cub->mlx_wind);
	if (cub->mlx)
		free(cub->mlx);
}
