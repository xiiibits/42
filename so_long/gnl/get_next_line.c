/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:14:53 by afahs             #+#    #+#             */
/*   Updated: 2025/06/30 03:16:39 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buf(int fd, char *stash, char *buffer)
{
	ssize_t	buf;
	char	*temp;

	buf = 1;
	while (buf > 0)
	{
		buf = read(fd, buffer, BUFFER_SIZE);
		if (buf == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (buf == 0)
			break ;
		buffer[buf] = 0;
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*clean_stash(char *line)
{
	char	*stash;
	ssize_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == 0)
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - 1);
	if (*stash == 0)
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = 0;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buf)
	{
		free(stash);
		free(buf);
		return (NULL);
	}
	line = read_buf(fd, stash, buf);
	free (buf);
	if (!line)
		return (NULL);
	stash = clean_stash(line);
	return (line);
}
