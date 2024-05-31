/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/30 16:20:38 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*rebuf(char *buf, int len)
{
	int	i;

	i = 0;
	if (buf[len] == '\n')
		len++;
	while (buf[len])
		buf[i++] = buf[len++];
	while (buf[i])
		buf[i++] = '\0';
	return (buf);
}

void	ft_bzero(char *buf, int len)
{
	int	i;

	i = 0;
	while (i < len)
		buf[i++] = 0;
}

char	*conmalloc(char	*result, char *buf, int len)
{
	char	*final;
	int		i;
	int		len_res;

	if (buf[len] == '\n')
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
		final[i] = buf[i - len_res];
		i++;
	}
	final[len_res + len] = '\0';
	free(result);
	return (final);
}
