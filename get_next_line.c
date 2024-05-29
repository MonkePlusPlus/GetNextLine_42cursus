/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:44 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/19 19:37:42 by ptheo            ###   ########.fr       */
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

char	*get_next_line_aux(int fd, char buf[BUFFER_SIZE], char *result, int i)
{
	int	current;

	rebuf(buf, BUFFER_SIZE);
	current = read(fd, buf, BUFFER_SIZE);
	while (current > -1)
	{
		i = 0;
		while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, buf, i);
		if (result == NULL)
			return (NULL);
		if (buf[i] == '\n' || current == 0)
		{
			rebuf(buf, i);
			return (result);
		}
		ft_bzero(buf, BUFFER_SIZE);
		current = read(fd, buf, BUFFER_SIZE);
	}
	ft_bzero(buf, BUFFER_SIZE);
	free(result);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*result;
	int			i;

	result = NULL;
	i = 0;
	if (buf[0] != '\0')
	{
		while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, buf, i);
		if (result == NULL)
		{
			return (NULL);
		}
		if (buf[i] == '\n')
		{
			rebuf(buf, i);
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