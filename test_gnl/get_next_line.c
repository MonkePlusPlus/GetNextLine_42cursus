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

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char		*result;
	int			current;
	int			i;

	result = NULL;
	i = 0;
	if (buf[0] != '\0')
	{
		while (buf[i])
			i++;
		result = conmalloc(result, buf, i);
		rebuf(buf, i);
	}
	while ((current = read(fd, buf, BUFFER_SIZE)) != -1)
	{
		while (buf[i] && buf[i] != '\n' && i < BUFFER_SIZE)
			i++;
		result = conmalloc(result, buf, i);
		if (current == 0 || buf[i] == '\n')
			return (result);
	}
	return (NULL);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	ft_putstr(get_next_line(fd));
	return (0);	
}
