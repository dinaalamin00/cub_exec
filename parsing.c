// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parsing.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/12 16:38:18 by sbakhit           #+#    #+#             */
// /*   Updated: 2024/12/28 18:27:05 by diahmed          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../cub3d.h"

// int	file_parsing(const char *map_path)
// {
// 	static char const	*file_format = ".cub";
// 	int					i;
// 	int					j;

// 	i = ft_strlen(map_path) - 1;
// 	j = 3;
// 	while (file_format[j] && map_path[i] == file_format[j] && i >= 0)
// 	{
// 		i--;
// 		j--;
// 		if (j == -1)
// 			return (1);
// 	}
// 	return (0);
// }
