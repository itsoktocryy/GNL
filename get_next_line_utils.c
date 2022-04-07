/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzachara <rzachara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:02:33 by rzachara          #+#    #+#             */
/*   Updated: 2022/04/07 20:03:11 by rzachara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *input, char *buff)
{
	size_t		x;
	size_t		y;
	char		*str;

	if (!input)
	{
		input = malloc(sizeof(char) * 1);
		input[0] = '\0';
	}
	if (!input || !buff)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(input) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	x = -1;
	y = 0;
	while (input[x++] != '\0')
		str[x] = input[x];
	while (buff[y] != '\0')
		str[x++] = buff[y++];
	str[ft_strlen(input) + ft_strlen(buff)] = '\0';
	free(input);
	return (str);
}
