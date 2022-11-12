/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/12 18:10:24 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_less(char *buf, int j, size_t buf_size)
{
	int		i;
	int		len;
	char	*tmp;

	i = ft_strlen(buf);
	tmp = malloc(j + 1);
	len = 0;
	while (len < j)
	{
		tmp[len] = buf[len];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	*joining(char *buf, char *tmp, size_t buff_size, int j)
{
	char	*str;
	int		i;
	char	*tmp2;

	if (ft_strchr(tmp, '\n') != 0)
	{
		// printf("1\n");
		tmp2 = ft_strjoin(buf, tmp);
		i = ft_strlen(tmp2);
		str = malloc(i + 2);
		i = 0;
		while (tmp2[i] != '\0')
		{
			str[i] = tmp2[i];
			i++;
		}
		str[i] = '\n';
		str[i + 1] = '\0';
	}
	else if (ft_strchr(buf, '\n') == 0 && j < buff_size && j != 0)
	{
		// printf("2\n");
		tmp = rest_less(tmp, j, buff_size);
		str = ft_strjoin(buf, tmp);
	}
	else if (j > 0)
	{
		// printf("3\n");
		str = ft_strjoin(buf, tmp);
	}
	else
	{
		// printf("4\n");
		return (buf);
	}
	return (str);
}

char	*saving(char *buf, char *tmp)
{
	char	*str;
	int		i;
	int		j;
	int		len;

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
	return (tmp);
}

char	*get_next_line(int fd)
{
	size_t			buff_size;
	static char		*tmp;
	char			*buf;
	int				j;
	int				i = 0;

	buff_size = 3;
	i = 0;
	if (buf)
		buf = saving(tmp, buf);
	else
		buf = calloc(buff_size + 1, sizeof(char));
	tmp = calloc(buff_size + 1, sizeof(char));
	j = 1;
	while (ft_strchr(tmp, '\n') == 0 && j != 0)
	{
		j = read(fd, tmp, buff_size);
		if (j == -1)
		{
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		buf = joining(buf, tmp, buff_size, j);
		if (j == 0 && i == 0)
			return (NULL);
		i++;
	}
	return (buf);
}

int main()
{
	int fd = open("f.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}