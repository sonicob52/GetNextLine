/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:19 by frgarci2          #+#    #+#             */
/*   Updated: 2024/11/28 17:24:13 by frgarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *f_stored(int fd, char *toline)
{
	char buffer[BUFFER_SIZE + 1];
	char *temp;
	ssize_t nbts;

	temp = NULL;
	while (!f_strt(toline, '\n'))
	{
		nbts = read(fd, buffer, BUFFER_SIZE);
		if (nbts == 0)
			break;
		if (nbts == -1)
		{
			free(toline);			
			return (NULL);
		}
		buffer[nbts] = '\0';
		temp = toline;
		toline = f_strjoin(toline, buffer);
		if (temp != NULL)
			free(temp);
	}
	return (toline);
}

char	*f_to_storeg(char *str)
{
	int		l1;
	int		l2;
	char	*rest;

	if (str == NULL)
		return (NULL);
	l1 = f_strlen(str);
	l2 = f_strlen(f_strt(str, '\n'));
	rest = f_sstr(str, (l1 - l2) + 1, l2 - 1);
	if (rest == NULL)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*temp[OPEN_MAX];
	char		*line;
	char		*result;

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = f_stored(fd, temp[fd]);
		if (!line)
	return (NULL);
	temp[fd] = f_to_storeg(line);
	result = f_get_line(line);
	free(line);
	return (result);
}

int main(void)
{
	int fd;
	char *line;
	int lines;

	lines = 1;
	fd = open("frank.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", lines++, line);
		free(line);
	}

	close(fd);
	return (0);
}
