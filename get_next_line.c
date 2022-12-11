/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:45:07 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/11 21:42:15 by abdamoha         ###   ########.fr       */
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
	char	*s;
	char	*f;
	
	i = 0;
	f = ft_strdup(tmp);
	// printf("f = %p\n", f);
	// if (buf && )
	// {
		// printf("sav\n");
	// 	str = ft_strjoin(str, buf);
	// }
	if (ft_strchr(tmp, '\n') != 0)
	{
		// printf("1\n");
		tmp2 = ft_strjoin(str, f);
		// printf("tmp2 = %p\n", tmp2);
		s = malloc(ft_strlen(tmp2) + 2);
		// printf("str nl = %p\n", s);
		while (tmp2[i] != '\0')
		{
			s[i] = tmp2[i];
			i++;
		}
		s[i] = '\n';
		s[i + 1] = '\0';
		free(f);
		// free(str);
		free(tmp2);
		return (s);
	}
	else if (j == BUFFER_SIZE)
	{
		// printf("2\n");
		s = ft_strjoin(str, f);
		// printf("str or = %p\n", s);
		free(f);
		// free(str);
		return (s);
	}
	else if (j < BUFFER_SIZE && j != 0)
	{
		// printf("3\n");
		tmp2 = rest_less(f, j);
		// printf("tmp2 rest = %p\n", tmp2);
		s = ft_strjoin(str, tmp2);
		// printf("str rest = %p\n", str);
		// if (str)
		// 	free(str);
		free(tmp2);
		// free(tmp);
		free(str);
		// free(f);
		return (s);
	}
	// printf("4\n");
	free(f);
	free(tmp);
	return (str);
}

char	*saving(char *buf)
{
	char		*str1;
	int			i;
	size_t		j;
	int			len;

	i = 0;
	j = ft_strlen(buf);
	buf[j] = '\0';
	// printf("buf saving = %p\n", buf);
	// if (!buf[0])
	// 	return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
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
	// printf("str saving = %p\n", str1);
	// free(buf);
	// if (str1 == NULL)
	// {
	// free(str1);
	// 	return (NULL);
	// }
	return (str1);
}

char	*del_line(char *str)
{
	size_t		i;
	char		*new_line;

	i = 0;
	// printf("str in = %s\n", str);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if ((ft_strchr(str, '\n') == 0 && ft_strlen(str) == i) || (ft_strchr(str, '\n') == 1 && !str[i + 2]))
	{
		// printf("here\n");
		// printf("str in = %s\n", str);
		return (str);
	}
	// printf("1\n");
	if (str[i + 1] == '\0')
		return (str);
	new_line = ft_substr(str, i + 1, ft_strlen(str));
	// printf("new_line = %s\n", new_line);
	if (!*new_line)
		return (NULL);
	// free (str);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	static char		*buf;
	static char		*str;
	int				j;
	// char			*sav;

	tmp = NULL;
	// buf = NULL;
	j = 1;
	// i = 0;
	if (fd < 0)
		return (NULL);
	if (buf)
	{
		// printf("str = %s\n", str);
		str = ft_strjoin(str, buf);
		// printf("str buf = %p\n", str);
		if (buf[0] == '\n')
		{
			str = ft_substr(buf, 0, 1);
			buf = ft_substr(buf, 1, ft_strlen(buf) - 1);
			return (str);
		}
		else
		{
			// printf("joining str  = %s\n", sav);
			free(buf);
		}
	}
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
		// printf("bb = %d\n", ft_strchr(tmp,'\n'));
		// printf("b tmp  = %s\n", tmp);
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
		// printf("before tmp  = %s\n", tmp);
		
		// printf("j = %d\n", j);
		// printf("before tmp  = %p\n", tmp);
		// printf("before str  = %p\n", str);
		str = joining(str, tmp, j);
		// printf("after str  = %p\n", str);
		// printf("after tmp  = %p\n", tmp);
		if (ft_strchr(tmp, '\n') != 0)
		{
			// printf("here\n");
			buf = saving(tmp);
			// if (!*buf)
			// 	free(buf);
			// printf("sav str  = %p\n", buf);
			str = del_line(str);
			// printf("del str  = %s\n", buf);
			free (tmp);
			return (str);
		}
		j = read(fd, tmp, BUFFER_SIZE);
		// i++;
	}
	// printf("out tmp  = %s\n", tmp);
	if (j == 0 && *tmp)
	{
		// printf("here\n");
		str = del_line(str);
		free(tmp);
		// printf("del = %s\n", str);
		// return (sav);
	}
	if (j == 0 && !*tmp)
	{
		// printf("hereee\n");
		free(tmp);
		// free(str);
		// free(buf);
		return (NULL);
	}
	// printf("str = %s\n", str);
	return (str);
}

// int main()
// {
// 	// int i = 0;
// 	int fd = open("f2.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	free(line);
// 	line = get_next_line(fd);
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
//  	// while (line)
// 	// {
// 		printf("%s", line);
// 		// free(line);
// 	// 	line = get_next_line(fd);
// 	// }
// 	// free(line);
// 	close (fd);
// }