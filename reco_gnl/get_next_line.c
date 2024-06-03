/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:15 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/03 22:00:23 by ptheo            ###   ########.fr       */
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

void	ft_bzero(char *str)
{
	int	i;

	i = 0;
	while (str && i < BUFFER_SIZE)
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

	result = NULL;
	if (check_still(stat) >= 0)
	{
		buf = stat;
		temp = check_n(stat);
		result = ft_concat(NULL, stat, temp);
		if (result == NULL)
		{
			free(buf);
			return (NULL);
		}
		if (temp < BUFFER_SIZE && temp > -1)
		{
			rebuf(buf, temp);
			return (result);
		}
		ft_bzero(buf);
	}
	else
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	temp = read(fd, buf, BUFFER_SIZE);
	while (temp > -1)
	{
		i = check_n(buf);
		if (i < BUFFER_SIZE && i > -1)
		{
			result = ft_concat(result, buf, i);
			if (result == NULL)
			{
				free(buf);
				return (NULL);
			}
			rebuf(buf, i);
			return (result);
		}
		result = ft_concat(result, buf, BUFFER_SIZE);
		if (result == NULL)
		{
			free(buf);
			return (NULL);
		}
		if (temp == 0)
			return (free(buf), stat = NULL, result);
		ft_bzero(buf);
		temp = read(fd, buf, BUFFER_SIZE);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int	fd;
	(void)ac;
	fd = open(av[1], O_RDONLY);
	printf("1er  appel : %s\n", get_next_line(fd));
	printf("2eme appel : %s\n", get_next_line(fd));
	printf("3eme appel : %s\n", get_next_line(fd));
	printf("4eme appel : %s\n", get_next_line(fd));
	printf("5eme appel : %s\n", get_next_line(fd));
	printf("6eme appel : %s\n", get_next_line(fd));
	printf("7eme appel : %s\n", get_next_line(fd));
	printf("8eme appel : %s\n", get_next_line(fd));
	printf("9eme appel : %s\n", get_next_line(fd));
	/*get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));
	ft_putstr(get_next_line(fd));*/
	return (0);
}
