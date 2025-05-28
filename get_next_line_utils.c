/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:33:03 by shmiyosh          #+#    #+#             */
/*   Updated: 2025/05/24 16:01:48 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, char ch)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *dest, char *src)
{
	char	*array;
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen_gnl(dest);
	src_len = ft_strlen_gnl(src);
	array = malloc(sizeof(char) * (dest_len + src_len + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < dest_len)
	{
		array[i] = dest[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		array[dest_len + i] = src[i];
		i++;
	}
	array[dest_len + i] = '\0';
	return (array);
}

char	*ft_substr_gnl(char *str, int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*array;

	i = 0;
	if (!str)
		return (NULL);
	str_len = ft_strlen_gnl(str);
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	if ((size_t)start >= str_len)
		return (ft_strdup_gnl(""));
	if (str_len < start + len)
		len = str_len - start;
	while (i < len)
	{
		array[i] = str[start];
		i++;
		start++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strdup_gnl(char *str)
{
	size_t	i;
	size_t	len;
	char	*array;

	i = 0;
	len = ft_strlen_gnl(str);
	array = malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	while (i < len)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}
