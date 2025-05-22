/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:32:42 by shmiyosh          #+#    #+#             */
/*   Updated: 2025/05/16 15:32:58 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	read_size;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_size = 1;
	while (!ft_strchr_gnl(remainder, '\n') && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		buffer[read_size] = '\0';
		free(remainder);
		remainder = ft_strjoin_gnl(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
}

static char	*trim_line(char *remainder)
{
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_until_newline(fd, remainder);
	if (!remainder)
		return (NULL);
	newline = extract_line(remainder);
	remainder = trim_line(remainder);
	return (newline);
}
