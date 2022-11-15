/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/15 18:58:40 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_less(char *buf, int j)
{
	int		len;
	char	*tmp;

	tmp = malloc(j + 1);
	if (!tmp)
		return (NULL);
	len = 0;
	while (len < j)
	{
		tmp[len] = buf[len];
		len++;
	}
	tmp[len] = '\0';
	// free(buf);
	return (tmp);
}

char	*joining(char *buf, char *tmp, int j)
{
	char	*str;
	int		i;
	char	*tmp2;

	if (ft_strchr(tmp, '\n') != 0)
	{
		tmp2 = ft_strjoin(buf, tmp);
		i = ft_strlen(tmp2);
		str = malloc(i + 2);
		if (!str)
			return (NULL);
		i = 0;
		while (tmp2[i] != '\0')
		{
			str[i] = tmp2[i];
			i++;
		}
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	else if (ft_strchr(buf, '\n') == 0 && j < BUFFER_SIZE && j != 0)
	{
		tmp = rest_less(tmp, j);
		str = ft_strjoin(buf, tmp);
		free(tmp);
	}
	else if (j > 0)
		str = ft_strjoin(buf, tmp);
	else
		return (buf);
	return (str);
}

char	*saving(char *buf, char *tmp)
{
	char		*str;
	int			i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	len = j - i;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
	{
		str[j++] = buf[i++];
	}
	str[j] = '\0';
	tmp = ft_strjoin(tmp, str);
	// free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buf;
	int				j;

	buf = NULL;
	if (tmp)
		buf = saving(tmp, buf);
	else
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	j = 1;
	while (ft_strchr(tmp, '\n') == 0 && j > 0)
	{
		j = read(fd, tmp, BUFFER_SIZE);
		if (j == -1)
		{
			free(tmp);
			return (NULL);
		}
			buf = joining(buf, tmp, j);
		if (*buf == 0)
			return (NULL);
	}
	return (buf);
}

int main()
{
	int fd = open("f2.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}
