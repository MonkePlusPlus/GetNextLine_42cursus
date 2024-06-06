/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:19 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/06 16:51:58 by ptheo            ###   ########.fr       */
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
	//printf("buf : %s %zu\n", s2, len);
	//printf("result : %s %zu\n", s1, len_s1);
	result = malloc((len + len_s1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1 && i < len_s1)
	{
		result[i] = s1[i];
		//printf("result[i] : %c\n", result[i]);
		i++;
	}
	while (j < len)
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*rebuf(char *buf, int len)
{
	char	*new_buf;
	int		i;
	int		len_f;

	i = 0;
	len_f = (ft_strlen(buf) - i);
	if (buf[0] != 0)
		new_buf = malloc(sizeof(char) * (len_f + 1));
	else
		new_buf = NULL;
	if (new_buf == NULL)
		return (NULL);
	while (i < len && buf[len])
	{
		new_buf[i] = buf[len];
		len++;
		i++;
	}
	new_buf[i] = '\0';
	//printf("new_buf : %s\n", new_buf);
	free(buf);
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