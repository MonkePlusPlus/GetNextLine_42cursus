/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/06 16:56:11 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_bzero(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (str && i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*buf;
	char		*result;
	int			temp;
	int			i;

	if (fd < 0)
		return (NULL);
	result = NULL;
	i = check_n(stat);
	//printf("check_n call : %d\n", i);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (i > -1)
		temp = 2;
	else
		temp = read(fd, buf, BUFFER_SIZE);
	while (temp > 0)
	{
		stat = buf;
		//printf("buf : %s\n", buf);
		i = check_n(buf);
		//printf("i : %d\n", i);
		if (i > -1)
			break;
		//printf("result avant : %s\n", result);
		result = ft_concat(result, buf, BUFFER_SIZE);
		//printf("result apres : %s\n", result);
		if (result == NULL)
		{
			free(buf);
			return (NULL);
		}
		free(buf);
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		stat = buf;
		temp = read(fd, buf, BUFFER_SIZE);
	}
	if (temp == 0)
	{
		free(buf);
		stat = NULL;
		return (result);
	}
	if (temp == -1)
	{
		free(buf);
		return (NULL);
	}
	result = ft_concat(result, buf, i + 1);
	if (result == NULL)
	{
		free(buf);
		return (NULL);
	}
	stat = rebuf(stat, i);
	//printf("stat : %s\n", stat);
	if (stat == NULL)
		return (NULL);
	return (result);
}

int	main(int ac, char **av)
{
	int	fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);/*
	printf("1er  appel : %s", get_next_line(fd));
	printf("2eme appel : %s", get_next_line(fd));
	printf("3eme appel : %s", get_next_line(fd));
	printf("4eme appel : %s", get_next_line(fd));
	printf("5eme appel : %s\n", get_next_line(fd));
	printf("6eme appel : %s\n", get_next_line(fd));
	printf("7eme appel : %s\n", get_next_line(fd));
	printf("8eme appel : %s\n", get_next_line(fd));
	printf("9eme appel : %s\n", get_next_line(fd));*/
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);/*
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);*/
	/*
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));*/
	return (0);
}
