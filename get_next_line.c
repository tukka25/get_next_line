/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/19 00:19:53 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_limited_edition(char *str)
{
	size_t	i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (s1 == NULL)
		return (NULL);
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

	if (buf == NULL || !buf)
		return (NULL);
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

char	*handle(char *buf, int j)
{
	int		len;
	char	*tmp;
	int		i;

	i = 0;
	while (buf[i - 1] != '\n' && buf[i])
		i++;
	tmp = malloc(j - i + 1);
	if (!tmp)
		return (NULL);
	len = 0;
	while (len < j - i)
	{
		tmp[len] = buf[len + 1];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
char	*saving(char *buf, int d)
{
	char		*str1;
	int			i;
	size_t		j;
	int			v;
	size_t		len;

	i = 0;
	v = 0;
	if (!buf)
		return (NULL);
	j = ft_strlen(buf);
	// printf("j = %zu", j);
	// printf("buf sav = %s\n", buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	// printf("i = %d\n", i);
	if ((!buf[i]) || (i + 1 == d && buf[i] == '\n'))
	{
		// printf("first\n");
		return (NULL);
	}
	if (buf[0] == '\n' && buf[i + 1])
	{
		// printf("fffffffffff\n");
		str1 = handle(buf, d);
		// printf("str1 = %s", str1);
		return (str1);
	}
	// if (d < BUFFER_SIZE)
	// {
	// 	j = 0;
	// 	// printf("heheh i = %d\n", i);
	// 	i++;
	// 	len = i;
	// 	while (buf[i] && buf[i] != '\n')
	// 		i++;
	// 	i++;
	// 	v = i;
	// 	while(buf[i] && buf[i] != '\n')
	// 	{
	// 		j++;
	// 		i++;
	// 	}
	// 	// printf("i = %d\n", i);
	// 	str1 = ft_substr(buf, len, j);
	// 	// printf("str1 sub = [[%s]]\n", str1);
	// 	g = ft_strdup(buf);
	// 	// printf("buf sav = {[%s]}\n", g);
	// 	// free(buf);
	// 	// // buf = NULL;
	// 	buf = ft_substr(g, v, ft_strlen(g));
	// 	// printf("buf after = [[[[%s]]]]\n",buf);
	// 	return (str1);
	// }
	// printf("buf i = {%c}\n", buf[i]);
	// printf("buf i + 1 = {%c}\n", buf[i + 1]);
	// if (buf[i] == '\n' && buf[i + 1] == '\n' && buf[i + 1] == '\n')
	// 	i++;
	i++;
	len = j - i;
	// printf("len = %zu\n", len);
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	j = 0;
	while (buf[i] != '\0')
	{
		str1[j] = buf[i];
		// printf("str = {%c}\n", str1[j]);
		j++;
		i++;
	}
	str1[j] = '\0';
	// printf("ft_l = %zu\n", ft_strlen(str1));
	if (*str1 == '\0')
	{
		free (str1);
		return (NULL);
	}
	// printf("str sav = %s\n", str1);
	return (str1);
}

char	*get_next_line(int fd)
{
	static char			*tmp;
	static char		*buf;
	char			*str;
	char			*sav;
	int				j;
	
	str = NULL;
	tmp = NULL;
	j = 1;
	if (fd < 0)
		return (NULL);
	if (buf)
	{
		// buf = saving(tmp, j);
		str = ft_strjoin(str, buf);
		if (buf[0] == '\n')
		{
			str = ft_substr(buf, 0, 1);
			sav = ft_strdup(buf);
			free(buf);
			buf = ft_substr(sav, 1, ft_strlen(sav) - 1);
			free(sav);
			return (str);
		}
		else
		{
			if (buf != NULL)
			{
				free(buf);
				buf = NULL;
			}
		}
	}
	// buf = saving(tmp, j);
	// printf("buf = %s\n", buf);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	j = read(fd, tmp, BUFFER_SIZE);
	if (j <= -1)
	{
		free(tmp);
		free(str);
		return (NULL);
	}
	tmp[j] = '\0';
	while (j > 0)
	{
		// printf("j = %d\n", j);
		// printf("before tmp  = %s\n", tmp);
		// printf("before str  = %s\n", str);
		str = joining(str, tmp, j);
		// printf("after str  = {{{%s}}}\n", str);
		// printf("after tmp  = {{{%s}}}\n", tmp);
		if (ft_strchr(tmp, '\n') != 0)
		{
			buf = saving(tmp, j);
			// printf("buf in = %s\n", buf);
			free (tmp);
			return (str);
		}
		j = read(fd, tmp, BUFFER_SIZE);
	}
	// printf("out str = %s\n", str);
	if ((j == 0 && *tmp != '\0'))
	{
		// printf("on\n");
		// if (*tmp)
			free(tmp);
		return (str);
	}
	else if (j == 0 && *tmp == '\0' && str == NULL && buf == NULL)
	{
		// printf("off\n");
		free(tmp);
		free(str);
		free(buf);
		return (NULL);
	}
		free(tmp);
	return (str);
}

// int main()
// {
// 	int fd = open("f2.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("join = %s", joining(NULL, "fhvjf", 4));
// 	// check_leaks();
//  	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close (fd);
// }

// // int main()
// // {
// // 	char *line;
// // 	int		i;
// // 	int		fd;

// // 	// fd = open("f2.txt", O_RDONLY);
// // 	// if (fd == -1)
// // 	// {
// 		printf("bad file");
// // 	// 	return (0);
// // 	// }
// // 	// i = 0;
// // 	// line = NULL;
// 	printf("%s", saving("kka\n", 4));
// // 	// while(i < 1)
// // 	// {
// // 	// 	line = get_next_line(fd);
// 		printf("%s", line);
// // 	// 	if (line)
// // 	// 		free(line);
// // 	// 	i++;
// // 	// }
// // 	return (0);
// // }
//joining
//100% zay elfol leaks 
// 4 or 5 functions every function do one thing only
//after making each function , make test cases ()
//make the new function  test cases make sure 