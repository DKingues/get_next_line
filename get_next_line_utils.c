/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:03:04 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/26 20:52:34 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Copy Nbytes from buffer to line and clear buffer.

size_t	linelen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *buff, char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc((linelen(buff) + linelen(line) + 1) * sizeof(char));
	if (!str)
		return (free(line), NULL);
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (*buff)
	{	
		str[i++] = *buff++;
		if (*buff == '\n')
		{
			str[i] = '\n';
			str[++i] = '\0';
			return (str);
		} 
	}	
	str[i] = '\0';
	free(line);
	return (str);
}

char	*buffer_clean(char *buffer)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (x < BUFFER_SIZE && buffer[x] != '\n')
	{
		buffer[x] = '\0';
		x++;
	}
	if (buffer[x] == '\n')
	{
		buffer[x] = '\0';
		x++;
		while(x < BUFFER_SIZE)
		{
			buffer[y] = buffer[x];
			buffer[x] = '\0';
			x++;
			y++;
		}
	}
	return (buffer);
}

