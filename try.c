#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int i = 0;
	char str[100];
	
	fd = open("f.txt", O_RDONLY);
		char *line;
		// line = get_next_line(fd);
		
		// free(line);
	// while(line != NULL)
	// {
	// 	printf("%s" , line);
	// 	line = get_next_line(fd);
	// }
size_t buf_size = 5;
// char *buf = malloc(buf_size);

read(fd, buf, buf_size);

printf("%s" , line);
close(fd);
}
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