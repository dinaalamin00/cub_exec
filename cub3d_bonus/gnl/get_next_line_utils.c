/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:41:07 by diahmed           #+#    #+#             */
/*   Updated: 2025/01/05 22:01:44 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	if (!s)
// 		return (0);
// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

size_t	line_len( char *s)
{
	size_t		i;
	size_t		len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			return (len);
		}
		i++;
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	total_size;

	total_size = nelem * elsize;
	if (nelem != 0 && elsize != 0 && total_size / elsize != nelem)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (((char *)s)[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (((char *)s)[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s2)
		return (NULL);
	ptr = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
