/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:44 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/30 16:50:48 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		write(1, "(null)", 6);
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*get_next_line_aux(int fd, char *buf, char *result, int i)
{
	char	*line;
	int		current;

	line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_bzero(line, BUFFER_SIZE);
	buf = line;
	current = read(fd, line, BUFFER_SIZE);
	while (current > -1)
	{
		i = 0;
		while (line[i] && line[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, line, i);
		if (result == NULL)
		{
			free(line);
			return (NULL);
		}
		if (line[i] == '\n')
		{
			rebuf(line, i);
			free(line);
			return (result);
		}
		if (current == 0)
		{
			buf = NULL;
			free(line);
			return (result);
		}
		ft_bzero(line, BUFFER_SIZE);
		current = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	free(result);
	buf = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*result;
	int			i;

	result = NULL;
	i = 0;
	line = NULL;
	if (buf != NULL)
	{
		line = buf;
		while (line[i] && line[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, line, i);
		if (result == NULL)
		{
			return (NULL);
		}
		if (line[i] == '\n')
		{
			rebuf(line, i);
			free(line);
			return (result);
		}
		free(line);
	}
	return (get_next_line_aux(fd, buf, result, i));
}
/*
int	main(int ac, char **av)
{
	int	fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	ft_putstr(get_next_line(fd));
	
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	return (0);	
}*/
