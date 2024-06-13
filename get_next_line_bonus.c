/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/13 16:32:37 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strlcpy(char *dest, char *src, int start, int end)
{
	int	i;

	i = 0;
	while (src[start] && i < end)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
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

char	**get_next_line_aux(int fd, char *stat)
{
	char	*buf;
	int		temp;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buf == NULL)
		return (free(stat), stat = NULL, NULL);
	temp = read(fd, buf, BUFFER_SIZE);
	while (temp > 0)
	{
		stat = ft_concat(stat, buf, BUFFER_SIZE);
		if (stat == NULL)
			return (NULL);
		if (check_n(stat) > -1)
			break ;
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (free(stat), stat = NULL, NULL);
		temp = read(fd, buf, BUFFER_SIZE);
	}
	if (temp == -1)
		return (free(buf), NULL);
	if (temp == 0)
		return (free(buf), rebuf(stat, ft_strlen(stat)));
	return (rebuf(stat, check_n(stat) + 1));
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	char		**result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_n(stat[fd]) > -1)
	{
		result = rebuf(stat[fd], check_n(stat[fd]) + 1);
		if (result == NULL)
			return (stat[fd] = NULL, NULL);
		return (temp = result[0], stat[fd] = result[1], free(result), temp);
	}
	result = get_next_line_aux(fd, stat[fd]);
	if (result == NULL)
	{
		if (stat[fd] != NULL)
			free(stat[fd]);
		return (stat[fd] = NULL, NULL);
	}
	return (temp = result[0], stat[fd] = result[1], free(result), temp);
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
