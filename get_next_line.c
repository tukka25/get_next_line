/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/21 19:56:33 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen_and_ft_strchr(s1, 0, 1);
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
	if (buf[0] == '\n')
		j--;
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
	size_t		len;

	i = 0;
	if (!buf)
		return (NULL);
	j = ft_strlen_and_ft_strchr(buf, 0, 1);
	while (buf[i] && buf[i] != '\n')
		i++;
	if ((!buf[i]) || (i + 1 == d && buf[i] == '\n'))
	{
		return (NULL);
	}
	if (buf[0] == '\n' && buf[i + 1])
	{
		str1 = handle(buf, d);
		return (str1);
	}
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
	if (*str1 == '\0')
	{
		free (str1);
		return (NULL);
	}
	return (str1);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	static char		*buf;
	char			*str;
	int				n_pos;
	int				j;

	str = NULL;
	tmp = NULL;
	n_pos = 0;
	j = 1;
	if (fd < 0)
		return (NULL);
	if (buf)
	{
		str = joining(str, buf, j);
		if (ft_strlen_and_ft_strchr(buf, '\n', 0) != 0)
		{
			tmp = buf;
			while (buf[n_pos] && buf[n_pos] != '\n')
				++n_pos;
			if (buf[n_pos] == '\n')
				++n_pos;
			buf = ft_strdup(&(buf[n_pos]));
			return (free(tmp), str);
		}
		else
		{
			free(str);
			if (buf[0] == 0)
				return (free(buf), NULL);
			str = ft_strdup(buf);
			free(buf);
			buf = NULL;
		}
	}
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	j = read(fd, tmp, BUFFER_SIZE);
	if (j <= -1)
		return (free(str), free(tmp), NULL);
	tmp[j] = '\0';
	while (j > 0)
	{
		str = joining(str, tmp, j);
		if (ft_strlen_and_ft_strchr(tmp, '\n', 0) != 0)
		{
			buf = saving(tmp, j);
			return (free(tmp), str);
		}
		j = read(fd, tmp, BUFFER_SIZE);
	}
	if ((j == 0 && *tmp != '\0'))
		return (free(tmp), str);
	else if (j == 0 && *tmp == '\0' && str == NULL && buf == NULL)
		return (free(tmp), free(str), free(buf), NULL);
	return (free(tmp), str);
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
// 	// free(line);
// 	close (fd);
// }
//joining
//100% zay elfol leaks 
// 4 or 5 functions every function do one thing only
//after making each function , make test cases ()
//make the new function  test cases make sure 