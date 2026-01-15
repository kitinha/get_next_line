/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:58:34 by marvin            #+#    #+#             */
/*   Updated: 2026/01/15 18:58:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char	*remainder;
    char		buffer[BUFFER_SIZE + 1];
    ssize_t		bytes_read;
    char		*newline_pos;
    char		*line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
        newline_pos = NULL;
        if (remainder)
            newline_pos = strchr(remainder, '\n');
        if (newline_pos)
            break ;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    if (bytes_read < 0 || (bytes_read == 0 && (!remainder || *remainder == '\0')))
    {
        free(remainder);
        remainder = NULL;
        return (NULL);
    }
    if (newline_pos)
    {
        size_t	line_length = newline_pos - remainder + 1;
        line = (char *)malloc(line_length + 1);
        if (!line)
            return (NULL);
        strncpy(line, remainder, line_length);
        line[line_length] = '\0';
        char *new_remainder = strdup(newline_pos + 1);
        free(remainder);
        remainder = new_remainder;
        return (line);
    }
    else
    {
        line = strdup(remainder);
        free(remainder);
        remainder = NULL;
        return (line);
    }
}