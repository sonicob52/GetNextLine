/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:19 by frgarci2          #+#    #+#             */
/*   Updated: 2024/11/27 18:32:23 by frgarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*f_stored(int fd, char *toline)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	nbts;

	while (!f_strt(toline, '\n'))
	{
		nbts = read(fd, buffer, BUFFER_SIZE);
		if (nbts == 0)
			break ;
		if (nbts == -1)
		{
			free(toline);
			return (NULL);
		}
		buffer[nbts] = '\0';
		toline = f_strjoin(toline, buffer);
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
	rest = f_sstr(str, (l1 - l2), l2);
	if (rest == NULL)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	line = f_stored(fd, temp);
	temp = f_to_storeg(line) + 1;
	return (f_get_line(line));
}
/*
int	main(void)
{
	int		fd;
	char		*line;
	//int		lines;

	//lines = 1;
	fd = open("frank.txt", O_RDONLY);
	//while ((line = get_next_line(fd)))
		//printf("%d->%s\n", lines++, line);
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));
	printf("Linea : %s\n", get_next_line(fd));

	close(fd);
	return (0);
}
*/
