/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/15 00:09:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int			len;

	i = 0;
	j = ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		// printf("on");
		return (NULL);
	}
	if (buf[0] == '\n' && buf[i + 1])
	{
		// printf("on");
		str1 = handle(buf, d);
		return (str1);
	}
	len = j - i;
	str1 = malloc(len + 1);
	if (!str1)
		return (NULL);
	j = 0;
	i++;
	while (buf[i] != '\0')
	{
		str1[j] = buf[i];
		j++;
		i++;
	}
	str1[j] = '\0';
	if (*str1 == '\0')
	{
		free (str1);
		return (NULL);
	}
	// printf("j = %d", j);
	return (str1);
}


char	*get_next_line(int fd)
{
	char			*tmp;
	static char		*buf;
	char			*str;
	int				j;
	
	str = NULL;
	tmp = NULL;
	j = 1;
	if (fd < 0)
		return (NULL);
	if (buf)
	{
		str = ft_strjoin(str, buf);
		if (buf[0] == '\n')
		{
			str = ft_substr(buf, 0, 1);
			buf = ft_substr(buf, 1, ft_strlen(buf) - 1);
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
		// printf("before tmp  = %p\n", tmp);
		// printf("before str  = %p\n", str);
		str = joining(str, tmp, j);
		// printf("after str  = %p\n", str);
		// printf("after tmp  = %p\n", tmp);
		if (ft_strchr(tmp, '\n') != 0)
		{
			buf = saving(tmp, j);
			// printf("buf = %s\n", buf);
			free (tmp);
			return (str);
		}
		j = read(fd, tmp, BUFFER_SIZE);
	}
	// printf("out str = %s\n", str);
	if ((j == 0 && *tmp != '\0'))
	{
		// printf("on\n");
		if (*tmp)
			free(tmp);
		return (str);
	}
	else if (j == 0 && *tmp == '\0')
	{
		// printf("off\n");
		free(tmp);
		free(str);
		free(buf);
		return (NULL);
	}
	return (str);
}




// int main()
// {
// 	// int i = 0;
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
// 	check_leaks();
//  	while (line)
// 	{
// 		printf("%s", line);
// 		// free(line);
// 		line = get_next_line(fd);
// 	}
// 	// free(line);
// 	close (fd);
// }

// int main()
// {
// 	char *line;
// 	int		i;
// 	int		fd;

// 	// fd = open("f2.txt", O_RDONLY);
// 	// if (fd == -1)
// 	// {
// 	// 	printf("bad file");
// 	// 	return (0);
// 	// }
// 	// i = 0;
// 	// line = NULL;
// 	// printf("%s", saving("kka\n", 4));
// 	// while(i < 1)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	if (line)
// 	// 		free(line);
// 	// 	i++;
// 	// }
// 	return (0);
// }
//joining
//100% zay elfol leaks 
// 4 or 5 functions every function do one thing only
//after making each function , make test cases ()
//make the new function  test cases make sure 