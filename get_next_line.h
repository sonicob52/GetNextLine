/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:58 by frgarci2          #+#    #+#             */
/*   Updated: 2024/11/27 16:54:28 by frgarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>	
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	f_strlen(const char *str);
char	*f_strt(const char *str, char t);
char	*f_sstr(const char *str, int start, size_t len);
char	*f_strjoin(char *s1, char const *s2);
char	*f_get_line(char *buffer);
char	*f_to_storeg(char *buffer);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*f_stored(int fd, char *temp);
#endif
