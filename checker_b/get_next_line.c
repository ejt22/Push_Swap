/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejoo-tho <ejoo-tho@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:45:41 by ejoo-tho          #+#    #+#             */
/*   Updated: 2022/07/06 15:20:22 by ejoo-tho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*	The function read_and_stash reads the file referenced by fd and returns
	what is read until '\n' or end of file is encountered.*/

char	*read_and_stash(int fd, char *stash, int *error)
{
	char	*buffer;
	ssize_t	count;

	count = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!search_newline(stash) && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			*error = 1;
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

/*	The function extract_line takes the stash with a line containing '\n' or
	end of file and eliminates everything that is after '\n'.*/

char	*extract_line(char *line_in)
{
	char	*line_out;
	int		len;
	int		i;

	len = 0;
	if (line_in && !line_in[len])
		return (NULL);
	while (line_in[len] && line_in[len] != '\n')
		len++;
	if (line_in[len] == '\n')
		len++;
	line_out = malloc(sizeof(char) * (len + 1));
	if (!line_out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line_out[i] = line_in[i];
		i++;
	}
	line_out[i] = '\0';
	return (line_out);
}

/*	The function clean_up takes the stash and cleans it up, ie gets rid of the
	line that is retuned by get_next_line.*/

char	*clean_up(char *line_in)
{
	char	*cleaned_line;
	int		len;
	int		i;

	if (!line_in)
		return (NULL);
	len = 0;
	while (line_in[len] && line_in[len] != '\n')
		len++;
	if (line_in[len] == '\n')
	{
		len++;
		cleaned_line = malloc(sizeof(char) * (ft_strlen(line_in + len) + 1));
		if (cleaned_line)
		{
			i = 0;
			while (line_in[len])
				cleaned_line[i++] = line_in[len++];
			cleaned_line[i] = '\0';
		}
		free(line_in);
		return (cleaned_line);
	}
	free(line_in);
	return (NULL);
}

char	*get_next_line(int fd, int *error)
{
	static char	*stash;
	char		*line_out;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		*error = 1;
		return (NULL);
	}
	stash = read_and_stash(fd, stash, error);
	line_out = extract_line(stash);
	stash = clean_up(stash);
	return (line_out);
}
