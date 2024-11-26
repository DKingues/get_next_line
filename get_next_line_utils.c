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

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strcpy(char *buffer, char *line)
{
	int	i;
	
	i = 0;
	if(!buffer || !line)
		return (NULL);
	while(buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*ft_strcat(char *src, char *dst)
{
	int		i;
	int		j;
	
	i = 0;
	j = ft_strlen(dst);
	if(!src || !dst)
		return (NULL);
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[i] = 0;
	return (dst);
}