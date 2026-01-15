/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:58:50 by marvin            #+#    #+#             */
/*   Updated: 2026/01/15 18:58:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t	len = 0;

    if (!s)
        return (0);
    while (s[len] != '\0')
        len++;
    return (len);
}
char	*ft_strjoin(char *s1, char *s2)
{
    size_t	len1 = ft_strlen(s1);
    size_t	len2 = ft_strlen(s2);
    char	*joined;
    size_t	i, j;

    joined = (char *)malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    i = 0;
    j = 0;
    while (i < len1)
    {
        joined[i] = s1[i];
        i++;
    }
    while (j < len2)
    {
        joined[i + j] = s2[j];
        j++;
    }
    joined[i + j] = '\0';
    free(s1);
    return (joined);
}

void    ft_bzero(void *s, size_t n)
{
    size_t  i;
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}
