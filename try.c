// #include "get_next_line.h"
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	int i = 0;
// 	char str[100];
	
// 	fd = open("f.txt", O_RDONLY);
// 		char *line;
// 		// line = get_next_line(fd);
		
// 		// free(line);
// 	// while(line != NULL)
// 	// {
// 	// 	printf("%s" , line);
// 	// 	line = get_next_line(fd);
// 	// }
// size_t buf_size = 5;
// // char *buf = malloc(buf_size);

// read(fd, buf, buf_size);

// printf("%s" , line);
// close(fd);
// }
// static int	len_check(char const *s1, char const *s2)
// {
// 	int	len_1;
// 	int	len_2;
// 	int	len;

// 	len_1 = 0;
// 	len_2 = 0;
// 	if (s1 == NULL)
// 	{
// 		len_1 = 0;
// 		len_2 = ft_strlen(s2);
// 	}
// 	else if (s2 == NULL)
// 	{
// 		len_2 = 0;
// 		len_1 = ft_strlen(s1);
// 	}
// 	else
// 	{
// 		len_1 = ft_strlen(s1);
// 		len_2 = ft_strlen(s2);
// 	}
// 	len = len_1 + len_2;
// 	return (len);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		len;
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (s1 == NULL && s2)
// 		return ((char *)s2);
// 	if (s2 == NULL && s1)
// 		return ((char *)s1);
// 	i = 0;
// 	j = 0;
// 	len = len_check(s1, s2);
// 	str = (char *)malloc(len * sizeof(char) + 1);
// 	if (!str)
// 		return (0);
// 	while (s1[i] != '\0')
// 		str[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i] != '\0')
// 		str[j++] = s2[i++];
// 	str[j] = '\0';
// 	// free(s2);
// 	// // free(s1);
// 	return (str);
// }
// int main()
// {
// 	int k = 0;
// 	char *tmp;
// 	char *dst;

// 	dst = malloc(1);
// 	dst = "afghte";
// 	tmp = malloc(5);
// 	tmp = "abcde";
// 	// while (k < 2)
// 	// {
// 	// 	k++;
// 	// 	printf("%s\n", ft_strcpy(tmp, k));
// 	// 	// k++;
// 	// }
// 	printf("%s", ft_strjoin(tmp, dst));
// }

// int 		i;
// 	size_t		buf_size;
// 	static char		*buf;
// 	char		ch;
// 	int			j;
// 	char		tmp[buffer];

// 	i = 0;
// 	j = 0;
// 	buf_size = 0;
// 	while ((read(fd, &ch, 1) == 1 && i < 1024))
// 	{
// 		if (ch == '\n')
// 		{
// 			tmp[i] = '\0';
// 			printf("%zu %d\n", buf_size, i);
// 			// printf("%s\n", tmp);
// 			buf = malloc(buf_size);
// 			// i--;
// 			// printf("%s", copying_in_string(tmp, i));
// 			ft_strcpy(buf, tmp);
// 			buf_size = 0;
// 			i++;
// 		}
// 		// printf("%d\n", i);
// 		tmp[i++] = ch;
// 		// if (i > 9)
// 		// 	printf("%c", tmp[i]);
// 		buf_size++;
// 	}
// 	// printf("%zu\n", buf_size);
// 	// 	buf = malloc(buf_size + 1);
// 	// 	fd = read(fd, buf, buf_size);
// 	// // 	i--;

// 	return (buf);
// }


// if (read(fd, buf, buf_size) == 1)
// {
// 	join;
// 	get_next_line(read)
// }

// har	*saving(char *buf, char *tmp)
// {
// 	char	*str;
// 	int		i;
// 	int		j;
// 	int		len;

// 	i = 0;
// 	j = ft_strlen(buf);
// 	while (buf[i] != '\n')
// 		i++;
// 	len = j - i;
// 	str = malloc(j + 1);
// 	if (!str)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (buf[i] != '\0')
// 	{
// 		str[j++] = buf[i++];
// 	}
// 	str[j] = '\0';
// 	// printf("str = %s\n", str);
// 	tmp = ft_strjoin(tmp, str);
// 	return (tmp);
// }






/*/////////////////////////////////////////////////

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
	if (ft_strchr(buf, '\n') != 0)
	{
		str = ft_strjoin(tmp, buf);
		i = ft_strlen(str);
		// tmp2 = ft_strdup(str);
		// str = ft_strdup(tmp2);
		// if (str)
		// {
		// 	str[i] = '\n';
		// 	str[i + 1] = '\0';
		// 	// free(tmp2);
		// }
	}
	else if (ft_strchr(buf, '\n') == 0 && j < buf_size && j != 0)
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

// char	*ignoring(char *tmp)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	j = 0;
// 	i = 0;
// 	while (tmp[i] != '\n' && tmp[i])
// 		i++;
// 	if (!tmp)
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	str = malloc(ft_strlen(tmp) - i);
// 	if (!str)
// 		return (NULL);
// 	i += 1;
// 	while (tmp[i] != '\n' && tmp[i])
// 		str[j++] = tmp[i++];
// 	// str = saving(buf, tmp);
// 	str[j] = '\0';
// 	// free(tmp);
// 	return (str);
// }

char	*saving(char *buf, char *tmp)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
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

char	*get_next_line(int fd)
{
	int				buf_size;
	static char			*buf;
	int					j;
	char			*tmp;

	buf_size = 3;
	tmp = NULL;
	if (buf)
	{
		tmp = saving(buf, NULL);
		free(buf);
		buf = calloc(buf_size + 2, sizeof(char));
	}
	else
	{
		buf = calloc(buf_size + 2, sizeof(char));
		tmp = calloc(buf_size + 2, sizeof(char));
	}
	j = 1;
	while (ft_strchr(buf, '\n') == 0 && j != 0)
	{
		j = read(fd, buf, buf_size);
		//printf("10000\n");
		if (j == -1)
			return NULL;
		if (j < buf_size)
		{
			// free(buf);
			// buf = NULL;
			tmp = joining(tmp, buf, buf_size, j);
			free(buf);
			buf = NULL;
			//printf("900000\n");
			return (tmp);
		}
		// //printf("buf = %s\n", buf);
		//printf("j = %d\n", j);
		tmp = joining(tmp, buf, buf_size, j);
		// //printf("tmp = %s\n", tmp);
		// //printf("j = %d\n", j);
		// //printf("len = %zu\n", ft_strlen(tmp));
		// //printf("d");
	}
		//printf("999\n");
	return (tmp);
}

int main()
{
	int fd =open("f.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf(" a = %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}
//////////////////////////////////////////////////*/