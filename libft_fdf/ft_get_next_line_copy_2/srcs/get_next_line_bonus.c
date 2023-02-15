/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polpi <polpi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:36:38 by afaucher          #+#    #+#             */
/*   Updated: 2023/02/14 15:09:54 by polpi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * ft_strlen(stash) - i + 1);
	if (line == NULL)
		return (NULL);
	while (stash[i] != '\0')
	{
		line[j] = stash[i];
		i++;
		j++;
	}
	free (stash);
	line[j] = '\0';
	return (line);
}

char	*ft_extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

//Complète ma stash à l'aide de la fonction read, en passant par un buffer
char	*ft_fill_stash(int fd, char *stash)
{
	char	*buff;
	int		rd;

	rd = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (rd != 0 && ft_strchr(stash, '\n') == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[rd] = '\0';
		stash = ft_strjoin (stash, buff);
	}
	free (buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0 || fd > 4096)
	{
		free (stash[fd]);
		stash[fd] = 0;
		return (NULL);
	}
	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char) * 1);
		stash[fd][0] = 0;
	}
	stash[fd] = ft_fill_stash(fd, stash[fd]);
	if (*stash[fd] == 0)
	{
		free (stash[fd]);
		return (stash[fd] = 0);
	}
	line = ft_extract_line(stash[fd]);
	stash[fd] = ft_new_stash(stash[fd]);
	return (line);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}
*/