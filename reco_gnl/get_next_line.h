/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:02:21 by ptheo             #+#    #+#             */
/*   Updated: 2024/06/03 21:41:11 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_concat(char *s1, char *s2, size_t len);
char	*ft_calloc(size_t size, size_t number);
void	rebuf(char *buf, int len);
void	ft_bzero(char *str);
int		check_still(char *buf);
int		check_n(char *buf);
int		ft_strlen(char *str);

#endif