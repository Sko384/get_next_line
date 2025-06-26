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

static char	*append_and_check(ssize_t read_size, char *buffer, char *remainder)
{
	char	*joined;

	if (read_size == -1)
		return (free(buffer), free(remainder), NULL);
	buffer[read_size] = '\0';
	joined = ft_strjoin_gnl(remainder, buffer);
	free(remainder);
	if (!joined)
		return (free(buffer), NULL);
	return (joined);
}

static char	*read_until_newline(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	read_size;

	buffer = mymalloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(remainder), NULL);
	read_size = 1;
	while (!ft_strchr_gnl(remainder, '\n') && read_size > 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		remainder = append_and_check(read_size, buffer, remainder);
		if (!remainder)
			return (NULL);
	}
	free(buffer);
	if (!remainder || *remainder == '\0')
		return (free(remainder), NULL);
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
	if (!remainder || *remainder == '\0')
		return (free(remainder), remainder = NULL, NULL);
	newline_pos = ft_strchr_gnl(remainder, '\n');
	if (newline_pos)
	{
		newline = ft_substr_gnl(remainder, 0, newline_pos - remainder + 1);
		if (!newline)
			return (free(remainder), NULL);
		temp = ft_strdup_gnl(newline_pos + 1);
		if (!temp)
			return (free(remainder), NULL);
	}
	else
	{
		newline = ft_strdup_gnl(remainder);
		if (!newline)
			return (NULL);
		temp = NULL;
	}
	free(remainder);
	remainder = temp;
	return (newline);
}

#include <stdlib.h>
#include <time.h>

// グローバル変数で初期化状態を管理
static int	g_initialized = 0;

void	*mymalloc(size_t size)
{
	// 初回呼び出し時のみ乱数の種を設定
	if (!g_initialized)
	{
		srand((unsigned int)time(NULL));
		g_initialized = 1;
	}
	// 0-99の範囲で乱数生成（10%の確率で0-9が出る）
	if (rand() % 100 < 10)
	{
		printf("malloc failed");
		return (NULL); // 10%の確率で失敗
	}
	return (malloc(size)); // 90%の確率で成功
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("one_char.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
		free(line);
	}
	printf("\n");
	close(fd);
	return (0);
}
