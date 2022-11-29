/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/29 20:22:57 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1);
	str = (char *)malloc((i * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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
	
	f = ft_strdup(tmp);
	// printf("f = %p\n", f);
	if (ft_strchr(tmp, '\n') != 0 && j == BUFFER_SIZE)
	{
		// printf("\n im 1\n");
		// printf("tmp = %s\n", tmp);
		// printf("str = %s\n", str);
		// printf("1str = %p", str);
		tmp2 = ft_strjoin(str, f);
		// printf("1tmp2 = %s\n", tmp2);
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
		// s[i] = '\n';
		s[i] = '\0';
		if (j == 0)
			free(tmp);
		// printf("s = %p\n", s);
		free(tmp2);
		free(f);
		free(str);
		return (s);
	}
	else if (j < BUFFER_SIZE && j != 0)
	{
		// printf("\n im 2\n");
		tmp2 = rest_less(f, j);
		// printf("2tmp2 = %s\n", tmp2);
		buf = ft_strjoin(str, tmp2);
		// printf("buf = %s\n", buf);
		// if (str != NULL)
		// free(str);
		free(tmp2);
		free(str);
		free(f);
		return (buf);
	}
	else if (j > 0)
	{
		// printf("\n im 3\n");
		tmp2 = ft_strjoin(str, f);
		// if (*str != NULL)
		// {
		// // 	str = tmp2;
		// 	free(str);
		// }
		s = ft_strdup(tmp2);
		// printf("sstr = %p\n", str);
		free(str);
		free(f);
		// free(tmp);
		// printf("3tmp2 = %p\n", tmp);
		free(tmp2);
		// free(s);
		return (s);
	}
	else
	{
		// printf("\n im 4\n");
		free(f);
		// free(tmp);
		return (str);
	}
	// printf("outside str = %p\n", str);
	free(f);
	free(tmp);
	return (str);
}

char	*saving(char *buf, char *str)
{
	char		*str1;
	int			i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(buf);
	buf[j] = '\0';
	// printf("buf saving = %p\n", buf);
	while (buf[i] && buf[i - 1] != '\n')
		i++;
	// printf("i = %d\n", i);
	len = j - i;
	// printf("len = %d\n", len);
	str1 = malloc(len + 1);
	// printf("mstr saving = %p\n", str1);
	if (!str1)
		return (NULL);
	j = 0;
	// i--;
	while (buf[i] != '\0')
	{
		str1[j] = buf[i];
		// printf("{%c}", str1[j]);
		j++;
		i++;
	}
	// printf("j = %zu", j);
	str1[j] = '\0';
	str = ft_strjoin(str, str1);
	// printf("str saving = %p\n", str);
	free(buf);
	// if (str1 == NULL)
	// {
	free(str1);
	// 	return (NULL);
	// }
	return (str);
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
	{
		str = saving(tmp, str);
		// free(tmp);
		// printf("saving = %s\n", str);
	}
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (ft_strchr(tmp, '\n') == 0 && j > 0)
	{
		j = read(fd, tmp, BUFFER_SIZE);
		tmp[j] = '\0';
		if (j <= -1)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		// printf("j = %d\n", j);
		printf("before tmp  = %s\n", tmp);
		printf("before str  = %s\n", str);
		str = joining(str, buf, tmp, j);
		printf("after tmp = %s\n", tmp);
		printf("after str  = %s\n", str);
		if (*str == '\0')
		{
			free(tmp);
			free(str);
			return (NULL);
		}
	}
	if (*str == '\0' || j == 0)
	{
		free(tmp);
		free(str);
		return (NULL);
	}
	return (str);
}

int main()
{
	// int i = 0;
	int fd = open("f2.txt", O_RDONLY);
	char *line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// check_leaks();
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// free(line);
	close (fd);
}
