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
	return (tmp);
}

char	*joining(char *str, char *buf, char *tmp, int j)
{
	int		i;
	char	*tmp2;
	char	*s;
	char	*f;

	f = strdup(tmp);
	if (ft_strchr(tmp, '\n') != 0)
	{
		// printf("f = %s\n", f);
		// printf("str = %s\n", str);
		tmp2 = ft_strjoin(str, f);
		// printf("tmp2 = %s\n", tmp2);
		i = ft_strlen(tmp2);
		s = malloc(i + 2);
		if (!s)
			return (NULL);
		i = 0;
		while (tmp2[i] != '\0')
		{
			s[i] = tmp2[i];
			i++;
		}
		s[i] = '\n';
		s[i + 1] = '\0';
		// buf = s;
		// free(tmp2);
		// free(tmp);
		return (s);
	}
	else if (ft_strchr(tmp, '\n') == 0 && j < BUFFER_SIZE && j != 0)
	{
		tmp2 = rest_less(f, j);
		buf = ft_strjoin(str, tmp2);
		// if (str != NULL)
		// 	free(str);
		// buf = strdup(str);
		// free(tmp2);
		// free(f);
		return (buf);
	}
	else if (j > 0)
	{
		tmp2 = ft_strjoin(str, f);
		// if (*str != NULL)
		// {
		// // 	str = tmp2;
		// 	free(str);
		// }
		str = strdup(tmp2);
		// free(tmp2);
		// free(f);
		return (str);
	}
	else
		return (str);
	return (str);
}

char	*saving(char *buf, char *tmp)
{
	char		*str1;
	// char		*save;
	int			i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(tmp);
	j = ft_strlen(buf);
	buf[j] = '\0';
	while (buf[i] && buf[i] != '\n')
		i++;
	i++;
	len = j - i;
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	j = 0;
	while (buf[i] != '\0')
	{
		str1[j] = buf[i];
		j++;
		i++;
	}
	str1[j] = '\0';
	if (str1 == NULL)
		free(str1);
	return (str1);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buf;
	char			*str;
	int				j;
	int				i;

	str = NULL;
	buf = NULL;
	j = 1;
	i = 0;
	if (fd < 0)
		return (NULL);
	if (tmp)
		str = saving(tmp, str);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (ft_strchr(tmp, '\n') == 0 && j > 0)
	{
		j = read(fd, tmp, BUFFER_SIZE);
		if (j == -1)
		{
			free(tmp);
			return (NULL);
		}
		str = joining(str, buf, tmp, j);
		if (*tmp == 0 && *str == '\0')
		{
			free(tmp);
			return (NULL);
		}
	}
	return (str);
}

int main()
{
	int fd = open("f2.txt", O_RDONLY);
	char *line = get_next_line(fd);
	// check_leaks();
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// free(line);
	close (fd);
}
