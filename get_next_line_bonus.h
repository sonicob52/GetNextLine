/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:58 by frgarci2          #+#    #+#             */
/*   Updated: 2024/11/28 16:42:46 by frgarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>	
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

size_t	f_strlen(const char *str);
char	*f_strt(const char *str, char t);
char	*f_sstr(const char *str, size_t start, size_t len);
char	*f_strjoin(char *s1, char const *s2);
char	*f_get_line(char *buffer);

#endif
