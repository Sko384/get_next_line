/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:33:03 by shmiyosh          #+#    #+#             */
/*   Updated: 2025/05/24 02:42:12 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr_gnl(const char *str, char ch)
{
	int	i;

	i = 0;
	if (ch == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((&str[i]));
		i++;
	}
	return (NULL);
}

static char *ft_strjoin_gnl(char *dest, char *src)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!dest)
		return (src);
	while(dest[len] != '\0')
		len++;
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	return (dest);
}
