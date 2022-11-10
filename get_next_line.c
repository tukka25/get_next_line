/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:54 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/10 21:55:22 by abdamoha         ###   ########.fr       */
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
	// printf("buf = %s\n", buf);
	// printf("j = %d\n", j);
	while (len < j)
	{
		// printf("on");
		tmp[len] = buf[len];
		// printf("buf[%d] %c\n", len, buf[len]);
		len++;
	}
	// printf("tmp = %s\n", tmp);
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
		i = ft_strlen(str);
		tmp2 = ft_strdup(str);
		str = malloc(i + 2);
		str = ft_strdup(tmp2);
		// printf("str = %s", str);
		// printf("i = %d", i);
		str[i] = '\n';
		// str[i + 1] = '\0';
		// free(tmp2);
	}
	else if (strchr(buf, '\n') == 0 && j < buf_size && j != 0)
	{
		// printf("on1\n");
		buf = rest_less(buf, j, buf_size);
		// printf("buf = %s\n", buf);
		// printf("b str =%s", str);
		str = ft_strjoin(tmp, buf);
		// printf("str = %s\n", str);
	}
	else if (j > 0)
	{
		str = ft_strjoin(tmp, buf);
		// printf("ON");
	}
	else
		return (tmp);
	return (str);
}

char	*ignoring(char *tmp)
{
	char	*str;
	int		i;
	int		j;
	
	printf("on");
	j = 0;
	i = ft_strlen(tmp);
	while (tmp[i] != '\n')
		i++;
	// i += 1;
	printf("%d", i);
	str = malloc(ft_strlen(tmp) - i);
	i++;
	while (tmp[i] != '\n')
	{
		str[j] = tmp[i];
		j++;
		i++;
	}
	str[j] = '\0';
	// free(tmp);
	return (str);
}

char	*saving(char *buf, char *tmp)
{
	char	*str;

	str = ft_strdup(buf);
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	size_t				buf_size;
	char				*buf;
	int					j;
	static char			*tmp;

	buf_size = 3;
	if (buf)
		tmp = saving(buf, tmp);
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
			return (tmp);
		}
		// printf("buf = %s\n", buf);
		// printf("j = %d\n", j);
		tmp = joining(tmp, buf, buf_size, j);
		printf("tmp = %s\n", tmp);
		// printf("tmp = %s\n", tmp);
		printf("len = %zu\n", ft_strlen(tmp));
	}
	// tmp = ignoring(tmp);
	return (tmp);
}

int main()
{
	int fd =open("f.txt", O_RDONLY);
	char *line = get_next_line(fd);
	// printf("%s", line);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}