/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/15 17:18:55 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*result;
	int		i;
	int		len;

	if (s == NULL)
	{
		result = malloc(sizeof(char) * 1);
		if (result == NULL)
			return (NULL);
		return (result[0] = '\0', result);
	}
	i = 0;
	len = 0;
	while (s[len])
		len++;
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (free(s), NULL);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	free(s);
	return (result[i] = '\0', result);
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
		return (free(stat), NULL);
	temp = read(fd, buf, BUFFER_SIZE);
	while (temp > 0)
	{
		stat = ft_concat(stat, buf, BUFFER_SIZE);
		if (stat == NULL)
			return (NULL);
		if (check_n_len(stat, 1) > -1)
			break ;
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (buf == NULL)
			return (free(stat), NULL);
		temp = read(fd, buf, BUFFER_SIZE);
	}
	if (temp == -1)
		return (free(stat), free(buf), NULL);
	if (temp == 0)
		return (free(buf), rebuf(stat, check_n_len(stat, 0)));
	return (rebuf(stat, check_n_len(stat, 1) + 1));
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		**result;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (check_n_len(stat, 1) > -1)
	{
		result = rebuf(stat, check_n_len(stat, 1) + 1);
		if (result == NULL)
			return (stat = NULL, NULL);
		return (temp = result[0], stat = result[1], free(result), temp);
	}
	temp = ft_strdup(stat);
	if (temp == NULL)
		return (stat = NULL, NULL);
	result = get_next_line_aux(fd, temp);
	if (result == NULL)
		return (stat = NULL, NULL);
	return (temp = result[0], stat = result[1], free(result), temp);
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
