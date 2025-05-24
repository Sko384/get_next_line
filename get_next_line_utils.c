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
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!dest)
		return (src);
	while (dest[len] != '\0')
		len++;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	return (dest);
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
