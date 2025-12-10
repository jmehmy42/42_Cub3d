/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:06:37 by jmehmy            #+#    #+#             */
/*   Updated: 2025/04/05 20:33:57 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[0])
		{
			line = gnl_strjoin(line, buffer);
			if (!line)
				return (NULL);
			if (gnl_strchr(line, '\n'))
				return (line);
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buffer[bytes_read] = '\0';
		}
	}
	return (line);
}
/*
int main()
{
	int fd;
	char *line;
	// const char *long = ("echo \"A$(head -c 15000 
	// 	< /dev/urandom | tr -dc 'a-zA-Z0-9')\" > long_test1.txt");
	// system(long);
	//system("echo \"hello\\n\" > test1.txt");
	fd = open("test1.txt", O_RDONLY);
	
	if (fd == -1)
		perror ("error");

	while((line = get_next_line(fd)) != NULL )
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
