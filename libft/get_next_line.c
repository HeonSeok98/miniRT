/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klha <klha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:03:59 by klha              #+#    #+#             */
/*   Updated: 2023/11/23 13:39:43 by klha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*separate_line(char **backup)
{
	int		i;
	char	*line;
	char	*previous_backup;

	i = 0;
	previous_backup = *backup;
	while (*previous_backup++ != '\n')
		i++;
	previous_backup = *backup;
	line = ft_substr(previous_backup, 0, i + 1);
	if (!line)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	*backup = ft_strdup(previous_backup + i + 1);
	if (!*backup)
	{
		free(line);
		line = 0;
	}
	free(previous_backup);
	previous_backup = 0;
	return (line);
}

static int	read_file(int fd, char *buffer, char **backup)
{
	int		read_result;
	char	*previous_backup;

	read_result = 1;
	while (!ft_strchr(*backup, '\n') && read_result)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result < 0)
			return (-1);
		buffer[read_result] = '\0';
		previous_backup = *backup;
		*backup = ft_strjoin(previous_backup, buffer);
		free(previous_backup);
		previous_backup = 0;
		if (!*backup)
			return (-2);
	}
	return (read_result);
}

static char	*get_line(int fd, char *buffer, char **backup)
{
	int		read_result;
	char	*last_line;

	read_result = read_file(fd, buffer, backup);
	if (!*backup || !**backup || read_result < 0)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	if (ft_strchr(*backup, '\n'))
		return (separate_line(backup));
	last_line = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	backup = 0;
	return (last_line);
}

static char	*free_backup(char **backup, int fd)
{
	if (*(backup + fd))
	{
		free(*(backup + fd));
		*(backup + fd) = 0;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX + 1];
	char		*buffer;
	char		*read_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_backup(backup, fd));
	if (!*(backup + fd))
	{
		*(backup + fd) = ft_strdup("");
		if (!*(backup + fd))
		{
			free(buffer);
			return (0);
		}
	}
	read_line = get_line(fd, buffer, &backup[fd]);
	free(buffer);
	buffer = 0;
	return (read_line);
}
