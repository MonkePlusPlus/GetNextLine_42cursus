/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:18:46 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/30 15:47:29 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	rebuf(char buf[1025][BUFFER_SIZE], int len, int fd)
{
	int	i;

	i = 0;
	if (buf[fd][len] == '\n')
		len++;
	while (buf[fd][len])
		buf[fd][i++] = buf[fd][len++];
	while (buf[fd][i])
		buf[fd][i++] = '\0';
}

void	ft_bzero(char buf[1025][BUFFER_SIZE], int len, int fd)
{
	int	i;

	i = 0;
	while (i < len)
		buf[fd][i++] = 0;
}

char	*conmalloc(char	*result, char buf[1025][BUFFER_SIZE], int len, int fd)
{
	char	*final;
	int		i;
	int		len_res;

	if (buf[fd][len] == '\n')
		len++;
	if (len <= 0)
		return (result);
	len_res = ft_strlen(result);
	final = (char *)malloc((len_res + len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = -1;
	while (++i < len_res)
		final[i] = result[i];
	while (i < len_res + len)
	{
		final[i] = buf[fd][i - len_res];
		i++;
	}
	final[len_res + len] = '\0';
	free(result);
	return (final);
}
