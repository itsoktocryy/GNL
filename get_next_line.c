/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzachara <rzachara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:01:52 by rzachara          #+#    #+#             */
/*   Updated: 2022/04/08 16:30:21 by rzachara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *input)
{
	int		i;
	char	*s;

	i = 0;
	if (!input[i])
		return (NULL);
	while (input[i] && input[i] != '\n')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (input[i] && input[i] != '\n')
	{
		s[i] = input[i];
		i++;
	}
	if (input[i] == '\n')
	{
		s[i] = input[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_reform(char *input)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (input[i] && input[i] != '\n')
		i++;
	if (!input[i])
	{
		free(input);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(input) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (input[i])
		s[c++] = input[i++];
	s[c] = '\0';
	free(input);
	return (s);
}

char	*ft_read(int fd, char *input)
{
	char	*buff;
	int		read_bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(input, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		input = ft_strjoin(input, buff);
	}
	free(buff);
	return (input);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*input;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	input = ft_read(fd, input);
	if (!input)
		return (NULL);
	line = ft_get_line(input);
	input = ft_reform(input);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	char	*line;
	int		i;
	int		fd;

	fd = open("tests/5.txt", O_RDONLY);
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("line [%d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}