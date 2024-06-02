/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:46:49 by ptheo             #+#    #+#             */
/*   Updated: 2024/05/31 21:22:49 by ptheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*get_next_line_aux(int fd, char *buf, int i);
char	*rebuf(char *buf, int len);
char	*conmalloc(char *result, char *buf, int len);
void	ft_bzero(char *buf, int len);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int		ft_strlen(char *str);

#endif
