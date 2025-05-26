/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:32:42 by shmiyosh          #+#    #+#             */
/*   Updated: 2025/05/24 15:05:42 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*read_until_newline(int fd, char *remainder)
// {
// 	char	*buffer;
// 	ssize_t	read_size;

// 	buffer = malloc(BUFFER_SIZE + 1);
// 	if (!buffer)
// 		return (NULL);
// 	read_size = 1;
// 	while (!ft_strchr_gnl(remainder, '\n') && read_size > 0)
// 	{
// 		read_size = read(fd, buffer, BUFFER_SIZE);
// 		if (read_size == -1)
// 		{
// 			free(buffer);
// 			free(remainder);
// 			return (NULL);
// 		}
// 		buffer[read_size] = '\0';
// 		remainder = ft_strjoin_gnl(remainder, buffer);
// 	}
// 	free(buffer);
// 	return (remainder);
// }

static char	*read_until_newline(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	read_size;
	char	*joined;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(remainder);
		return (NULL);
	}
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
		joined = ft_strjoin_gnl(remainder, buffer);
		if (!joined)
		{
			free(buffer);
			free(remainder);
			return (NULL);
		}
		remainder = joined;
	}
	free(buffer);
	if (!remainder || *remainder == '\0')
	{
		free(remainder);
		return (NULL);
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*newline;
	char		*newline_pos;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_until_newline(fd, remainder);
	if (!remainder)
		return (NULL);
	newline_pos = ft_strchr_gnl(remainder, '\n');
	if (newline_pos)
	{
		newline = ft_substr_gnl(remainder, 0, newline_pos - remainder + 1);
		temp = ft_strdup_gnl(newline_pos + 1);
	}
	else
	{
		newline = ft_strdup_gnl(remainder);
		temp = NULL;
	}
	free(remainder);
	remainder = temp;
	return (newline);
}
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		write(1, line, ft_strlen_gnl(line));
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
