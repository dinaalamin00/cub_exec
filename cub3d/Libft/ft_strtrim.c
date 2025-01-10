/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:45:51 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/08 11:08:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		j;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (!s1 || !*s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]) && j > i)
		j--;
	ptr = malloc((j - i + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1 + i, j - i + 2);
	return (ptr);
}
