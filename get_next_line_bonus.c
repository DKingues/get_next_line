/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:08:05 by dicosta-          #+#    #+#             */
/*   Updated: 2024/12/06 17:43:19 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(buffer[fd], line);
		if (!line)
			return (NULL);
		buffer_clean(buffer[fd]);
		if (line[linelen(line) - 1] == '\n')
			break ;
	}
	return (line);
}

// int main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
//     int fd1 = open("test1.txt", O_RDONLY);
// 	char *line;
//     char *line1;
// 	int 	i = 0;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
//         line1 = get_next_line(fd1);
// 		printf("%s", line);
//         printf("%s", line1);
// 		free(line);
//         free(line1);
// 		i++;
// 	}
// }