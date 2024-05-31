/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:18:24 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/30 15:55:23 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line_aux(int fd, char buf[1025][BUFFER_SIZE], char *result,
	int i)
{
	int	current;

	rebuf(buf, BUFFER_SIZE, fd);
	current = read(fd, buf[fd], BUFFER_SIZE);
	while (current > -1)
	{
		i = 0;
		while (buf[fd][i] && buf[fd][i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, buf, i, fd);
		if (result == NULL)
			return (NULL);
		if (buf[fd][i] == '\n' || current == 0)
		{
			rebuf(buf, i, fd);
			return (result);
		}
		ft_bzero(buf, BUFFER_SIZE, fd);
		current = read(fd, buf[fd], BUFFER_SIZE);
	}
	ft_bzero(buf, BUFFER_SIZE, fd);
	free(result);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[1025][BUFFER_SIZE];
	char		*result;
	int			i;

	result = NULL;
	i = 0;
	if (buf[fd][0] != '\0')
	{
		while (buf[fd][i] && buf[fd][i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, buf, i, fd);
		if (result == NULL)
		{
			return (NULL);
		}
		if (buf[fd][i] == '\n')
		{
			rebuf(buf, i, fd);
			return (result);
		}
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
}
*/