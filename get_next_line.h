/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:32:13 by shmiyosh          #+#    #+#             */
/*   Updated: 2025/05/24 15:03:57 by shmiyosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char		*ft_strchr_gnl(char *str, char ch);
char		*ft_strjoin_gnl(char *dest, char *src);
char		*ft_substr_gnl(char *str, int start, size_t len);
char		*ft_strdup_gnl(char *str);

#endif
