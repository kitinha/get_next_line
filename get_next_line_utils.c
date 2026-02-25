/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineguill <ineguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:20:15 by ineguill          #+#    #+#             */
/*   Updated: 2026/02/25 18:17:52 by ineguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(length(line) + length(buffer) + 1);
	if (!str)
		return (free(line), NULL);
	i = 0;
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		str[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	return (free(line), str);
}

void	ft_consume_line(char *buffer)
{
	int	r;
	int	b;

	r = 0;
	b = 0;
	while (buffer[b] != '\n' && buffer[b])
		b++;
	if (buffer[b] == '\n')
		b++;
	while (buffer[r])
	{
		buffer[r] = buffer[b];
		r++;
		b++;
	}
	buffer[r] = '\0';
}
