/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:54 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/09 23:10:09 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*sa3ad(char *tmp, char *buf, size_t buf_size)
{
	char	*str;
	int		i;
	char	*tmp2;

	i = 0;
	str = NULL;
	str = ft_strjoin(tmp, buf);
	// free(buf);
	buf = malloc((buf_size + 1) * sizeof(char));
	return (str);
}

char	*get_next_line(int fd)
{
	size_t			buf_size;
	static char		*buf;
	int				j;
	char			*tmp;

	tmp = NULL;
	buf_size = 3;
	if (buf)
		tmp = saving(buf, tmp);
	else
		tmp = malloc(buf_size + 2);
	buf = malloc(buf_size + 2);
	j = 1;
	while (ft_strchr(buf, '\n') == 0 && j != 0)
	{
		// printf("\nbuf = %s\n", buf);
		// printf("\nj = %d\n", j);
		tmp = sa3ad(tmp, buf, buf_size);
		j = read(fd, buf, buf_size);
		if (j == 0)
		{
			// free(buf);
			buf = NULL;
			return (NULL);
		}
	}
	if (j < buf_size)
	{
		tmp = sa3ad(tmp, buf, buf_size);
	}
	return (tmp);
}

char	*saving(char *buf, char *tmp)
{
	char	*str;

	str = ft_strdup(buf);
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}

int main()
{
	int fd =open("f.txt", O_RDONLY);
	char *line = get_next_line(fd);
	// printf("%s", line);

	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}