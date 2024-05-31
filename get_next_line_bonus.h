/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:18:39 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/30 15:47:36 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get_next_line_aux(int fd, char buf[1025][BUFFER_SIZE], char *result,
			int i);
void	rebuf(char buf[1025][BUFFER_SIZE], int len, int fd);
char	*conmalloc(char *result, char buf[1025][BUFFER_SIZE], int len, int fd);
void	ft_bzero(char buf[1025][BUFFER_SIZE], int len, int fd);
int		ft_strlen(char *str);

#endif