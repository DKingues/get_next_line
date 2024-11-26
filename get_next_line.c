/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:44 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/26 21:06:37 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		nbytes;
	int		i;
	
	nbytes = 10;
	i = 0;
	buffer = malloc(sizeof(char) * nbytes);
	if (!buffer || read(fd, buffer, 0 < 0))
		return (NULL);
	while (read(fd, buffer, nbytes) > 0)
	{
		ft_strcat(buffer, line);
		i++;
	}
	free(buffer);
	return (line);
}

//size_t read(int fd, void *buf, size_t nbyte);
// read file, by n bytes
//transfer buf to a new arr,
// clear buff, do it again,
//if a newline is found, add before the newline to arr,
//start again from the end of newline

//Use Open to declare the file descriptor (FD);

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY | O_CREAT);
	printf("%s\n",get_next_line(fd));
}