/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caterras <caterras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:34:11 by caterras          #+#    #+#             */
/*   Updated: 2024/02/17 18:34:15 by caterras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <get_next_line.h>

int fill_storage(fd, *storage)
{
	int	i;
	int	flag;
	char *buffer;
	int	n;


	flag = 0;
	n = 1;
	while(!flag)
	{
		buffer = malloc(BUFFER_SIZE * sizeof(char));
		if(read(fd, buffer, BUFFER_SIZE) < 0)
			return (NULL);
		i = 0;
		while(buffer[i])
		{
			if(buffer[i] == '\n' || buffer[i] == '\0')
				flag = 1;
			i++;
		}
		if (flag = 1 & n = 1)
		{
			storage = malloc(BUFFER_SIZE * sizeof(char));
			i = 0;
			while(buffer[i])
			{
				storage[i] = buffer[i];
				i++;
			}
			free(buffer);
		}
		else
		{
			storage = strjoin(storage, buffer);
			free(buffer);
			n++;
		}
	}
}

clear_storage(i, *storage)
{
	int	j;

	j = 0;
	while(storage[i])
	{
		storage[j] = storage[i];
	}
	storage[j] = '\n';
}

char *get_next_line(int fd)
{
	static char	*storage=NULL;
	char 		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (fill_storage(fd, storage) < 0)
		return (NULL);
	
	i = 0;
	while(storage[i] != '\n' || storage[i] != '\0')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = storage[i];
	i++;
	clear_storage(i, storage);

	return(line);
}

int main() 
{
	fd = open("/Users/caterras/Cursus/test_file.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return 0;
}