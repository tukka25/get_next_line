/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/16 22:02:02 by abdamoha         ###   ########.fr       */
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
	printf("tmp = %p\n", tmp);
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
		printf("tmp2 = %p\n", tmp2);
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
		// printf("i = %d\n", i);
		str[i] = '\n';
		str[i + 1] = '\0';
		printf("str1 = %p\n", str);
		// free(tmp);
		free(tmp2);
	}
	else if (ft_strchr(buf, '\n') == 0 && j < BUFFER_SIZE && j != 0)
	{
		tmp2 = rest_less(tmp, j);
		printf("tmp2 = %p\n", tmp2);
		str = ft_strjoin(buf, tmp2);
		free(tmp2);
	}
	else if (j > 0)
	{
		str = ft_strjoin(buf, tmp);
		printf("str2 = %p\n", str);
		// free(tmp);
	}
	else
	{
		printf(" else = %s", buf);
		// free(tmp);
		return (buf);
	}
	return (str);
}

char	*saving(char *buf, char *tmp)
{
	char		*str1;
	int			i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(buf);
	printf("buf = %s\n", buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	len = j - i;
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
	{
		str1[j++] = buf[i++];
	}
	str1[j] = '\0';
	tmp = ft_strjoin(tmp, str1);
	printf("saving = %p\n", tmp);
	if (str1 == NULL)
		free(str1);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buf;
	char			*str;
	int				j;

	buf = NULL;
	if (fd < 0)
		return (NULL);
	if (tmp)
	{
		buf = saving(tmp, buf);
		// free(tmp);
	}
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
		printf("buf = %p\n", buf);
		printf("tmp = %p\n", tmp);
		str = joining(buf, tmp, j);
		// free(buf);
		buf = str;
		// free(str);
		if (*buf == 0)
			return (NULL);
	}
	// free(tmp);
	return (buf);
}

int main()
{
	int fd = open("f2.txt", O_RDONLY);
	char *line = get_next_line(fd);
	check_leaks();
	while (line != NULL)
	{
		printf("%s", line);
		// check_leaks();
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}
