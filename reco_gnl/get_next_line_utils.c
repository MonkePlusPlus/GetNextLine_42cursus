/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:19 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/07 18:18:40 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_still(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (-1);
	while (buf && buf[i])
		i++;
	return (i);
}

int	check_n(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (-1);
	while (buf[i])
	{
		//printf("buf[i] : %c\n", buf[i]);
		if (buf[i] == '\n')
		{
			//printf("n : %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}
char	*ft_concat(char *s1, char *s2, size_t len)
{
	size_t	len_s1;
	size_t	i;
	size_t	j;
	char	*result;
	
	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	if (s2 == NULL)
		return (s1);
	//printf("buf : %s %zu\n", s2, len);
	//printf("result : %s %zu\n", s1, len_s1);
	result = (char *)malloc((len + len_s1 + 1) * sizeof(char));
	if (result == NULL)
		return (free(s1), NULL);
	while (s1 && i < len_s1)
	{
		result[i] = s1[i];
		//printf("result[i] : %c\n", result[i]);
		i++;
	}
	while (s2 && s2[j] && j < len)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	**rebuf(char *buf, int len)
{
	char	**new_buf;
	int		i;
	int		len_f;

	i = 0;
	if (buf == NULL)
		return (NULL);
	len_f = ft_strlen(buf) - len;
	if (buf[0] != 0)
	{
		new_buf = (char **)malloc(sizeof(char *) * (2));
		if (new_buf == NULL)
			return (free(buf), NULL);
		new_buf[0] = (char *)malloc(sizeof(char) * (len + 1));
		if (new_buf[0] == NULL)
			return (free(buf), free(new_buf), NULL);
		if (len_f > 0)
		{
			new_buf[1] = (char *)malloc(sizeof(char) * (len_f + 1));
			if (new_buf[1] == NULL)
				return (free(buf), free(new_buf[0]), free(new_buf), NULL);
		}
		else
			new_buf[1] = NULL;
	}
	else
		return (NULL);
	while (buf[i] && i < len)
	{
		new_buf[0][i] = buf[i];
		i++;
	}
	new_buf[0][i] = '\0';
	i = 0;
	if (new_buf[1])
	{
		while (buf[len] && i < len_f)
			new_buf[1][i++] = buf[len++];
		new_buf[1][i] = '\0';
	}
	free(buf);
	//printf("new_buf : %s\n", new_buf);
	return (new_buf);
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