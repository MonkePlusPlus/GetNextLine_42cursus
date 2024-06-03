/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:19 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/03 21:59:06 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_still(char *buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (-1);
	while (buf[i])
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
		if (buf[i] == '\n')
			return (i);
		i++;
	}
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
	len_s1 = ft_strlen(s1);
	result = malloc((len + len_s1 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1 && i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	while (j < len)
		result[i++] = s2[j++];
	free(s1);
	return (result);
}

void	rebuf(char *buf, int len)
{
	int	i;

	i = 0;
	while (len < BUFFER_SIZE && i < len)
		buf[i++] = buf[len++];
	while (i < BUFFER_SIZE)
		buf[i++] = '\0';
} 

char	*ft_calloc(size_t size, size_t number)
{
	char	*result;

	result = malloc(number * sizeof(size));
	if (result == NULL)
		return (NULL);
	ft_bzero(result);
	return (result);
}