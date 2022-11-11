/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:42 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/11 19:36:23 by abdamoha         ###   ########.fr       */
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

char	*joining(char *tmp, char *buf, size_t buf_size, int j)
{
	char	*str;
	int		i;
	char	*tmp2;

	i = 0;
	if (strchr(buf, '\n') != 0)
	{
		str = ft_strjoin(tmp, buf);
		// printf("str = %s", str);
		i = ft_strlen(str);
		tmp2 = ft_strdup(str);
		str = malloc(i + 2);
		str = ft_strdup(tmp2);
		str[i] = '\n';
		str[i + 1] = '\0';
		free(tmp2);
	}
	else if (strchr(buf, '\n') == 0 && j < buf_size && j != 0)
	{
		buf = rest_less(buf, j, buf_size);
		str = ft_strjoin(tmp, buf);
	}
	else if (j > 0)
		str = ft_strjoin(tmp, buf);
	else
		return (tmp);
	return (str);
}

char	*ignoring(char *tmp)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	str = malloc(ft_strlen(tmp) - i);
	if (!str)
		return (NULL);
	i += 1;
	while (tmp[i] != '\n' && tmp[i])
		str[j++] = tmp[i++];
	// str = saving(buf, tmp);
	str[j] = '\0';
	// free(tmp);
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
	while (buf[i] != '\n')
		i++;
	len = j - i;
	str = malloc(j + 1);
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

// char	*saving(char *buf, char *tmp)
// {
// 	char	*str;

// 	str = ft_strdup(buf);
// 	tmp = ft_strjoin(tmp, str);
// 	return (tmp);
// }

char	*get_next_line(int fd)
{
	size_t				buf_size;
	static char				*buf;
	int					j;
	char			*tmp;

	buf_size = 3;
	if (buf)
	{
		// printf("on\n");
		tmp = saving(buf, tmp);
		// printf("saving = %s\n", tmp);
	}
	else
		tmp = malloc(buf_size + 2);
	buf = malloc(buf_size + 2);
	j = 1;
	while (ft_strchr(buf, '\n') == 0 && j > 0)
	{
		j = read(fd, buf, buf_size);
		if (j == 0)
		{
			// free(buf);
			// buf = NULL;
			return (NULL);
		}
		// printf("buf = %s\n", buf);
		// printf("j = %d\n", j);
		tmp = joining(tmp, buf, buf_size, j);
		// printf("tmp = %s\n", tmp);
		// printf("len = %zu\n", ft_strlen(tmp));
		// printf("d");
	}
	// if (buf)
	// {
	// 	// printf("on\n");
	// 	// buf = saving(buf, tmp);
	// 	// printf("saving = %s\n", buf);
	// }
	// if(tmp[ft_strlen(tmp) + 1] != '\0')
		// tmp = ignoring(tmp);
	return (tmp);
}

int main()
{
	int fd =open("f.txt", O_RDONLY);
	char *line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}