/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/07 18:19:42 by ptheo            ###   ########.fr       */
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
	char		**result;
	char		*buf;
	int			temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = check_n(stat);
	//printf("check_n call : %d\n", i);
	buf = NULL;
	if (i > -1)
		temp = -2;
	else
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		temp = read(fd, buf, BUFFER_SIZE);
	}
	while (temp > 0)
	{
		//printf("buf : %s\n", buf);
		i = check_n(buf);
		//printf("i : %d\n", i);
		if (i > -1)
			break;
		//printf("result avant : %s\n", result);
		stat = ft_concat(stat, buf, BUFFER_SIZE);
		if (stat == NULL)
			return (free(buf), NULL);
		//printf("result apres : %s\n", result);
		free(buf);
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		temp = read(fd, buf, BUFFER_SIZE);
	}
	if (temp == 0)
	{
		free(buf);
		result = rebuf(stat, ft_strlen(stat));
		if (result == NULL)
			return (NULL);
		buf = result[0];
		return (stat = NULL, free(result), buf);
	}
	if (temp == -1)
		return (free(stat), stat = NULL, free(buf), NULL);
	stat = ft_concat(stat, buf, BUFFER_SIZE);
	if (stat == NULL)
	{
		if (temp > 0)
			free(buf);
		return (NULL);
	}
	result = rebuf(stat, check_n(stat) + 1);
	if (result == NULL)
	{
		if (temp > 0)
			free(buf);
		return (NULL);
	}
	//printf("result[0] : %s\n", result[0]);
	//printf("result[1] : %s\n", result[1]);
	if (temp > 0)
		free(buf);
	buf = result[0];
	return (stat = result[1], free(result), buf);
}
/*
int	main(int ac, char **av)
{
	char	*tmp;
	int		i = 1;
	int	fd;
	(void)ac;
	
	fd = open(av[1], O_RDONLY);
	while ((tmp = get_next_line(fd)))
	{
		printf("%deme appel : %s", i, tmp);
		free(tmp);
		i++;
	}
	printf("1er  appel : %s", get_next_line(fd));
	printf("2eme appel : %s", get_next_line(fd));
	printf("3eme appel : %s", get_next_line(fd));
	printf("4eme appel : %s", get_next_line(fd));
	printf("5eme appel : %s\n", get_next_line(fd));
	printf("6eme appel : %s\n", get_next_line(fd));
	printf("7eme appel : %s\n", get_next_line(fd));
	printf("8eme appel : %s\n", get_next_line(fd));
	printf("9eme appel : %s\n", get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	free(get_next_line(fd));
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}*/
