/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:21 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/14 15:01:01 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_concat(char *s1, char *s2, size_t len);
char	*ft_calloc(size_t size, size_t number);
char	**resmalloc(int len, int len_f);
char	**rebuf(char *buf, int len);
char	*ft_strlcpy(char *dest, char *src, int start, int end);
void	ft_bzero(char *str, size_t size);
int		check_n(char *buf);
int		ft_strlen(char *str);

#endif