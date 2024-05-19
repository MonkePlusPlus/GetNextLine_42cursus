/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/04/15 15:46:55 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_aux(int fd, int len)
{
	static char	*result;
	char		*buf;
	int			temp;
	int			i;

	i = 0;
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	temp = read(fd, buf, BUFFER_SIZE);
	if (temp == 0)
	{
		if (len == 0)
		{
			free(buf);
			return (NULL);
		}
		result = malloc((len + 1) * sizeof(char));
		if (!result)
			return (NULL);
		result[len] = 0;
		free(buf);
	}
	else if (temp == -1)
	{
		free(buf);
		return (NULL);
	}
	else 
	{
		while (buf[i] && i < BUFFER_SIZE && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
		{
			result = malloc((len + i + 2) * sizeof(char));
			if (!result)
				return (NULL);
			result[len + i + 1] = 0;
			i = 0;
			while(buf[i] && buf[i] != '\n')
				result[len++] = buf[i++];
			result[len + i] = '\n';
			free(buf);
		}
		else if (buf[i] == 0 && i < BUFFER_SIZE)
		{
			result = malloc((len + i + 1) * sizeof(char));
			if (!result)
				return (NULL);
			result[len + i] = 0;
			i = 0;
			while (buf[i])
				result[len++] = buf[i++];
			free(buf);
		}
		else
		{
			if (!get_next_line_aux(fd, len + BUFFER_SIZE))
			{
				free(buf);
				return (NULL);
			}
			i = 0;
			while (i < BUFFER_SIZE)
				result[len++] = buf[i++];
			free(buf);
		}
	}
	return (result);
}
