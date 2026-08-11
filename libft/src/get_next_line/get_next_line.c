/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschilli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:29:03 by nschilli          #+#    #+#             */
/*   Updated: 2026/02/11 12:01:27 by nschilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append(char *stash, char *buffer)
{
	char	*newstash;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	newstash = ft_strjoin(stash, buffer);
	free(stash);
	return (newstash);
}

char	*filler(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_byte;

	read_byte = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (free(buffer), free(stash), NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		stash = append(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*analyser(char *raw_stash)
{
	size_t		i;
	size_t		j;
	char		*line;

	i = 0;
	j = 0;
	if (!raw_stash || !*raw_stash)
		return (NULL);
	while (raw_stash[i] != '\n' && raw_stash[i] != '\0')
		i++;
	if (raw_stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = raw_stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*stash_update(char *stash)
{
	char	*newstash;
	size_t	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	newstash = ft_strdup(stash + i + 1);
	free(stash);
	if (!newstash)
		return (NULL);
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = filler(fd, stash);
	if (!stash)
		return (NULL);
	line = analyser(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = stash_update(stash);
	return (line);
}
