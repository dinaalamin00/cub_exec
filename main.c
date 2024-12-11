/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:31:17 by diahmed           #+#    #+#             */
/*   Updated: 2024/12/10 15:48:36 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"



int main(void)
{
	t_cub cub;

	ft_memset(&cub, 0, sizeof(t_cub *));
	// init_all(&cub);
	cub.mlx = mlx_init();
	if (!cub.mlx)
		return (0);
	cub.mlx_wind = mlx_new_window(cub.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!cub.mlx_wind)
		return (0);
	cub.img.img = mlx_new_image(cub.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub.img.img)
		return (0);
	cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, &cub.img.line_length, &cub.img.endian);
	if (!cub.img.addr)
		return (0);
	cub.map.map = malloc(6 * sizeof(char *));
	set_map(&cub.map);
	set_player(&cub.map);
	render_map(&cub);
	mlx_key_hook(cub.mlx_wind, events, &cub);
	// mlx_hook(cub.mlx_wind, 2, 0, &events, &cub);
	mlx_loop(cub.mlx);
	
	return 0;
}
