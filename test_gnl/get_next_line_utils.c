/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:54 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/19 19:32:38 by ptheo            ###   ########.fr       */
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

char	*rebuf(char* buf, int len)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[len])
			buf[i] = buf[len++];
		else
			buf[i] = '\0';
		i++;
	}
	return (buf);
}

char	*conmalloc(char	*result, char *buf, int len)
{
	char	*final;
	int		i;
	int		len_res;

	if (buf[len] == '\n')
		len++;
	len_res = ft_strlen(result);
	final = (char *)malloc((len_res + len + 1) * sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < len_res)
	{
		final[i] = result[i];
		i++;
	}
	while (i < len_res + len)
	{
		final[i] = buf[i - len_res];
		i++;
	}
	final[len_res + len] = '\0';
	rebuf(buf, len);
	free(result);
	return (final);
}
