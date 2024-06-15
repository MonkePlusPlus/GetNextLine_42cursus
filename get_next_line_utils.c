/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:19 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/15 17:18:56 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n_len(char *buf, int len)
{
	int	i;

	i = 0;
	if (buf == NULL && len)
		return (-1);
	while (buf && buf[i])
	{
		if (buf[i] == '\n' && len)
			return (i);
		i++;
	}
	if (len)
		return (-1);
	return (i);
}

char	*ft_concat(char *s1, char *s2, size_t len)
{
	size_t	len_s1;
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	len_s1 = check_n_len(s1, 0);
	if (s2 == NULL)
		return (s1);
	result = (char *)malloc((len + len_s1 + 1) * sizeof(char));
	if (result == NULL)
		return (free(s1), free(s2), NULL);
	while (s1 && s1[i] && i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && j < len)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (free(s1), free(s2), result);
}

char	**resmalloc(int len, int len_f)
{
	char	**new_buf;

	new_buf = (char **)malloc(sizeof(char *) * (2));
	if (new_buf == NULL)
		return (NULL);
	new_buf[0] = (char *)malloc(sizeof(char) * (len + 1));
	if (new_buf[0] == NULL)
		return (free(new_buf), NULL);
	if (len_f > 0)
	{
		new_buf[1] = (char *)malloc(sizeof(char) * (len_f + 1));
		if (new_buf[1] == NULL)
			return (free(new_buf[0]), free(new_buf), NULL);
	}
	else
		new_buf[1] = NULL;
	return (new_buf);
}

char	**rebuf(char *buf, int len)
{
	char	**new_buf;
	int		len_f;

	if (buf == NULL)
		return (NULL);
	len_f = check_n_len(buf, 0) - len;
	if (buf[0] == 0)
		return (free(buf), NULL);
	new_buf = resmalloc(len, len_f);
	if (new_buf == NULL)
		return (free(buf), NULL);
	new_buf[0] = ft_strlcpy(new_buf[0], buf, 0, len);
	if (new_buf[1] != NULL)
		new_buf[1] = ft_strlcpy(new_buf[1], buf, len, len_f);
	return (free(buf), new_buf);
}

char	*ft_calloc(size_t size, size_t number)
{
	char	*result;

	result = malloc(number * sizeof(size));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, number);
	return (result);
}
