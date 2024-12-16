/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:32 by frgarci2          #+#    #+#             */
/*   Updated: 2024/11/28 17:14:36 by frgarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	f_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*f_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = "";
	str = malloc(sizeof(char) * ((f_strlen(s1)) + (f_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*f_strt(const char *str, char t)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == t)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*f_sstr(const char *str, size_t start, size_t len)
{
	size_t	i;
	size_t	slen;
	int		j;
	char	*ss;

	i = start;
	j = 0;
	slen = f_strlen(str);
	if (str == NULL)
		return (NULL);
	if ((start + len) > slen)
		len = slen - start;
	if ((start) > slen)
		return (NULL);
	ss = (char *) malloc(sizeof(char *) * (len + 1));
	if (ss == NULL)
		return (NULL);
	while (str[i] != '\0' && (start + len) > i)
	{
		ss[j] = str[i];
		j++;
		i++;
	}
	ss[j] = '\0';
	return (ss);
}

char	*f_get_line(char *buffer)
{
	int		l1;
	int		l2;
	char	*line;

	if (buffer == NULL)
		return (NULL);
	l1 = f_strlen(buffer);
	l2 = f_strlen(f_strt(buffer, '\n')) + 1;
	line = f_sstr(buffer, 0, (l1 - l2) + 1);
	if (line == NULL)
		return (NULL);
	return (line);
}
