/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/11/17 22:09:50 by abdamoha         ###   ########.fr       */
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
	return (tmp);
}

char	*joining(char *str, char *buf, char *tmp, int j)
{
	int		i;
	char	*tmp2;
	char	*s;

	if (ft_strchr(tmp, '\n') != 0)
	{
		tmp2 = ft_strjoin(str, tmp);
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
		if (str != NULL)
			s[i] = '\n';
		s[i + 1] = '\0';
		buf = strdup(s);
		free(s);
		free(tmp2);
		return (buf);
	}
	else if (ft_strchr(str, '\n') == 0 && j < BUFFER_SIZE && j != 0)
	{
		tmp2 = rest_less(tmp, j);
		str = ft_strjoin(str, tmp2);
		buf = strdup(str);
		free(tmp2);
		// free(tmp);
		return (buf);
	}
	else if (j > 0)
	{
		tmp2 = ft_strjoin(str, tmp);
		free(tmp);
		str = strdup(tmp2);
	}
	else
	{
		free(tmp);
		return (str);
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
	while (buf[i] && buf[i] != '\n')
		i++;
	len = j - i;
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
		str1[j++] = buf[i++];
	str1[j] = '\0';
	tmp = ft_strjoin(tmp, str1);
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

	str = NULL;
	buf = NULL;
	if (fd < 0)
		return (NULL);
	if (tmp)
		str = saving(tmp, str);
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
		str = joining(str, buf, tmp, j);
		if (*tmp == 0)
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
		// free(line);
		line = get_next_line(fd);
	}
	// free(line);
	close (fd);
}

// #include "get_next_line.h"

// char	*rest_less(char *buf, int j)
// {
// 	int		len;
// 	char	*tmp;

// 	tmp = malloc(j + 1);
// 	if (!tmp)
// 		return (NULL);
// 	len = 0;
// 	while (len < j)
// 	{
// 		tmp[len] = buf[len];
// 		len++;
// 	}
// 	tmp[len] = '\0';
// 	return (tmp);
// }

// char	*joining(char **str, char *buf, char *tmp, int j)
// {
// 	int		i;
// 	char	*tmp2;
// 	char	*s;

// 	tmp2 = NULL;
// 	if (ft_strchr(tmp, '\n') != 0)
// 	{
// 		tmp2 = ft_strjoin(*str, tmp);
// 		if (str != NULL)
// 			free(str);
// 		i = ft_strlen(tmp2);
// 		s = malloc(i + 2);
// 		if (!s)
// 			return (NULL);
// 		i = 0;
// 		while (tmp2[i] != '\0')
// 		{
// 			s[i] = tmp2[i];
// 			i++;
// 		}
// 		if (*str != NULL)
// 			s[i] = '\n';
// 		s[i + 1] = '\0';
// 		buf = s;
// 		free(tmp2);
// 		return (buf);
// 	}
// 	else if (ft_strchr(tmp, '\n') == 0 && j < BUFFER_SIZE && j != 0)
// 	{
// 		printf("on\n");
// 		tmp2 = rest_less(tmp, j);
// 		buf = ft_strjoin(*str, tmp2);
// 		if (*str != NULL)
// 			free(str);
// 		buf = strdup(*str);
// 		free(tmp2);
// 		// free(tmp);
// 		return (buf);
// 	}
// 	else if (j > 0)
// 	{
// 		tmp2 = ft_strjoin(*str, tmp);
// 		// if (*str != NULL)
// 		// {
// 		// // 	str = tmp2;
// 		// 	free(str);
// 		// }
// 		// *str = strdup(tmp2);
// 		// free(tmp2);
// 		return (tmp2);
// 	}
// 	else
// 		return (*str);
	
// }

// char	*saving(char *buf, char *tmp)
// {
// 	char		*str1;
// 	int			i;
// 	size_t		j;
// 	int			len;

// 	i = 0;
// 	j = ft_strlen(buf);
// 	while (buf[i] && buf[i] != '\n')
// 		i++;
// 	len = j - i;
// 	str1 = malloc(len + 1);
// 	if (!str1)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (buf[i] != '\0')
// 		str1[j++] = buf[i++];
// 	str1[j] = '\0';
// 	tmp = ft_strjoin(tmp, str1);
// 	if (str1 == NULL)
// 		free(str1);
// 	return (tmp);
// }

// char	*get_next_line(int fd)
// {
// 	static char		*tmp;
// 	char			*buf;
// 	char			*str;
// 	int				j;
// 	int				i;

// 	str = NULL;
// 	buf = NULL;
// 	j = 1;
// 	i = 0;
// 	if (fd < 0)
// 		return (NULL);
// 	if (tmp)
// 		str = saving(tmp, str);
// 	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!tmp)
// 		return (NULL);
// 	while (ft_strchr(tmp, '\n') == 0 && j > 0)
// 	{
// 		j = read(fd, tmp, BUFFER_SIZE);
// 		if (j == -1)
// 		{
// 			free(tmp);
// 			return (NULL);
// 		}
// 		// printf("j = %d\n", j);
// 		// printf("tmp before  = %s\n", tmp);
// 		// printf("str before  = %s\n", str);
// 		str = joining(&str, buf, tmp, j);
// 		// printf("tmp after  = %s\n", tmp);
// 		// printf("str after  = %s\n", str);
// 		if (*tmp == 0)
// 		{
// 			free(tmp);
// 			return (NULL);
// 		}
// 	}
// 	return (str);
// }

// int main()
// {
// 	int fd = open("f2.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	// check_leaks();
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// free(line);
// 	close (fd);
// }