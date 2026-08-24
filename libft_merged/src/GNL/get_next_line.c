/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:05:43 by romeo             #+#    #+#             */
/*   Updated: 2026/02/01 16:28:39 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*clearing_string(char **s, char **s2)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
	if (s2 && *s2)
	{
		free (*s2);
		*s2 = NULL;
	}
	return (NULL);
}

static char	*cleaning_static_buffer(char **buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	new = NULL;
	if ((*buffer)[i])
	{
		while ((*buffer)[i + j])
			j++;
		new = malloc(sizeof(char) * (j + 1));
		if (!new)
			return (NULL);
		ft_strlcpy_gnl(new, (*buffer) + i, j + 1);
	}
	if (*buffer)
		free(*buffer);
	return (new);
}

static char	*processing(char **storage, char **local_buffer)
{
	size_t	count;
	char	*new_line;

	count = 0;
	while ((*storage)[count] && (*storage)[count] != '\n')
		count++;
	if ((*storage)[count] == '\n')
		count++;
	new_line = malloc(sizeof(char) * (count + 1));
	if (!new_line)
		return (clearing_string(storage, local_buffer));
	ft_strlcpy(new_line, *storage, count + 1);
	*storage = cleaning_static_buffer(storage);
	if (*local_buffer)
		free(*local_buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*local_buffer;
	char		*line;
	ssize_t		chr_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	local_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!local_buffer)
		return (clearing_string(&local_buffer, &static_buffer));
	chr_read = 1;
	while (chr_read)
	{
		chr_read = read(fd, local_buffer, BUFFER_SIZE);
		if (chr_read < 0)
			return (clearing_string(&local_buffer, &static_buffer));
		local_buffer[chr_read] = '\0';
		static_buffer = ft_strjoin_free_s1(static_buffer, local_buffer);
		if (!static_buffer)
			return (clearing_string(&local_buffer, &static_buffer));
		if (ft_strchr_gnl(local_buffer, '\n'))
			break ;
	}
	line = processing(&static_buffer, &local_buffer);
	return (line);
}
