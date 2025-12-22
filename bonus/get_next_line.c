/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:45:19 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 14:45:58 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*append_to_storage(char *storage, char *buffer, ssize_t bytes_read)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	if (!storage)
		return (ft_substr(buffer, 0, bytes_read));
	temp = ft_strjoin(storage, buffer);
	free(storage);
	return (temp);
}

static char	*read_file(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(4 + 1);
	if (!buffer || 4 < 0)
		return (NULL);
	bytes_read = read(fd, buffer, 4);
	while (bytes_read > 0)
	{
		storage = append_to_storage(storage, buffer, bytes_read);
		if (!storage || ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, 4);
	}
	free(buffer);
	if (bytes_read < 0)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

static char	*get_line_and_update_storage(char **storage, char *newline_pos)
{
	char	*line;
	char	*temp;
	size_t	line_len;

	line_len = newline_pos - *storage + 1;
	line = ft_substr(*storage, 0, line_len);
	temp = ft_substr(*storage, line_len, ft_strlen(*storage) - line_len);
	free(*storage);
	*storage = temp;
	if (*storage && **storage == '\0')
	{
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static char	*extract_line(char **storage)
{
	char	*newline_pos;
	char	*line;

	if (!*storage)
		return (NULL);
	newline_pos = ft_strchr(*storage, '\n');
	if (newline_pos)
		return (get_line_and_update_storage(storage, newline_pos));
	line = ft_substr(*storage, 0, ft_strlen(*storage));
	free(*storage);
	*storage = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || 4 <= 0)
		return (NULL);
	storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(&storage);
	return (line);
}
