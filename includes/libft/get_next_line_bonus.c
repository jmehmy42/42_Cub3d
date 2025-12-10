/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:06:02 by jmehmy            #+#    #+#             */
/*   Updated: 2024/12/26 16:35:02 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[fd][0])
		{
			line = gnl_strjoin(line, buffer[fd]);
			if (!line)
				return (NULL);
			if (gnl_strchr(line, '\n'))
				return (line);
		}
		else
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buffer[fd][bytes_read] = '\0';
		}
	}
	return (line);
}
/*int main ()
{
	int fd1, fd2, fd3;
	char *line1, *line2, *line3;
	system("touch test2.txt && touch test3.txt");
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 )
	{
		perror("Error opening file");
		return (1);
	}
	while ((line1 = get_next_line(fd1)) != NULL)
	{
		printf("%s", line1);
		free(line1);
	}
	while ((line2 = get_next_line(fd2)) != NULL)
	{
		printf("%s", line2);
		free(line2);
	}
	while ((line3 = get_next_line(fd3)) != NULL)
	{
		printf("%s", line3);
		free(line3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
