/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:44 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/31 21:38:28 by ptheo            ###   ########.fr       */
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

char	*ft_calloc(size_t length)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc(length * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

char	*get_next_line_aux(int fd, char *result, char *buf)
{
	char	*line;
	int		current;
	int		i;
	static int	temp = 0;

	line = ft_calloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	buf = line;
	current = read(fd, buf, BUFFER_SIZE);
	while (current > -1)
	{	
		i = 0;
		while (line[i] && line[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, line, i);
		/*ft_putchar(temp + '0');
		ft_putstr(" : ");
		ft_putstr(line);
		ft_putchar('\n');*/
		temp += 1;
		if (result == NULL)
			return (free(line), NULL);
		if (line[i] == '\n')
			return (rebuf(line, i), result);
		if (current == 0)
			return (buf = NULL, free(line), result);
		ft_bzero(line, BUFFER_SIZE);
		current = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	free(result);
	buf = NULL;
	return (NULL);
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{/*
		if (str[i] == '\n')
			ft_putchar('/');
		else
			ft_putchar(str[i]);*/
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*result;
	int			i;
	int			current;

	i = check_empty(buf);
	result = NULL;
	if (i > 0)
	{
		line = buf;
		result = conmalloc(result, line, i);
		if (result == NULL)
			return (NULL);
		if (line[i] == '\n')
		{
			rebuf(line, i);
			return (result);
		}
		free(line);
	}
	line = ft_calloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	buf = line;
	current = read(fd, line, BUFFER_SIZE);
	while (current > -1)
	{	
		i = 0;
		while (line[i] && line[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, line, i);
		/*ft_putchar(temp + '0');
		ft_putstr(" : ");
		ft_putstr(line);
		ft_putchar('\n');*/
		if (result == NULL)
			return (free(line), NULL);
		if (line[i] == '\n')
			return (rebuf(line, i), result);
		if (current == 0)
			return (buf = NULL, free(line), result);
		ft_bzero(line, BUFFER_SIZE);
		current = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	free(result);
	buf = NULL;
	return (NULL);
}
/*
int	main(int ac, char **av)
{
	int	fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	return (0);
}*/
