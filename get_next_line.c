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

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buf;
	char		*newline;
	int			bites_read;
	size_t		len;
	char		*newline;

	newline = strchr(buffer, '\n');
	while (!newline && (bites_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		*remainder = *bites_read;
		remainder++;
		if (bites_read == 0)
			break ;
	}
	if (newline)
	{
		len = newline - buf + 1;
		line = substr(buffer, 0, len);   // 改行まで含めた部分
		remainder = strdup(newline + 1); // 改行の次の文字から残り全て
	}
}
