/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/07 21:40:50 by abdamoha         ###   ########.fr       */
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

char	*joining(char *str, char *tmp, int j)
{
	int		i;
	char	*tmp2;
	static char	*s;
	char	*f;
	
	i = 0;
	f = ft_strdup(tmp);
	// printf("f = %p\n", f);
	if (s)
		str = ft_strjoin(s, str);
	if (ft_strchr(tmp, '\n') != 0)
	{
		tmp2 = ft_strjoin(str, f);
		str = malloc(ft_strlen(tmp2) + 2);
		while (tmp2[i] != '\0')
		{
			str[i] = tmp2[i];
			i++;
		}
		str[i] = '\n';
		str[i + 1] = '\0';
		s = saving(f, str);
		// printf("s = %s\n", s);
		free(f);
		// free(tmp);
		free(tmp2);
		return (str);
	}
	else if (j > 0)
	{
		str = ft_strjoin(str, f);
		free(f);
		// free(tmp);
		return (str);
	}
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
	while (buf[i] && buf[i] != '\n')
		i++;
	// printf("i = %d\n", i);
	len = j - i;
	// printf("len = %d\n", len);
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	j = 0;
	i++;
	while (buf[i] != '\0')
	{
		str1[j] = buf[i];
		// printf("{%c}", str1[j]);
		j++;
		i++;
	}
	// printf("j = %zu", j);
	str1[j] = '\0';
	// str = ft_strjoin(str, str1);
	// printf("str saving = %p\n", str);
	// free(buf);
	// if (str1 == NULL)
	// {
	// free(str1);
	// 	return (NULL);
	// }
	return (str1);
}
// 
char	*get_next_line(int fd)
{
	char			*tmp;
	static char		*buf;
	static char		*str;
	int				j;
	int				i;

	tmp = NULL;
	// buf = NULL;
	j = 1;
	i = 0;
	if (fd < 0)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
		// printf("bb = %d\n", ft_strchr(tmp,'\n'));
		// printf("b tmp  = %s\n", tmp);
	while (ft_strchr(tmp, '\n') == 0 && j > 0)
	{
		// printf("before tmp  = %s\n", tmp);
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
		str = joining(str, tmp, j);
		printf("after str  = %s\n", str);
		printf("after tmp  = %s\n", tmp);
		if (j == 0 && !*tmp)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		// j = read(fd, tmp, BUFFER_SIZE);
		i++;
	}
	// printf("before tmp  = %s\n", tmp);
	printf("j = %d\n", j);
	// printf("after str  = %s\n", str);
	// if (j == 0 && i == 0)
	// {
	// 	free(tmp);
	// 	free(str);
	// 	return (NULL);
	// }
	// printf("str = %s\n", str);
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
	// // line = get_next_line(fd);
	// free(line);
	// // line = get_next_line(fd);
	// free(line);
	// // line = get_next_line(fd);
	// free(line);
	// // line = get_next_line(fd);
	// free(line);
	// line = get_next_line(fd);
	// check_leaks();
 	while (line)
	{
		printf("%s", line);
		// free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
}