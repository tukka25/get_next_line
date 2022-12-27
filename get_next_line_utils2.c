/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:14:12 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/21 22:57:24 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joining(char *str, char *tmp, int j)
{
	int		i;
	char	*tmp2;
	char	*s;
	char	*f;

	i = 0;
	f = ft_strdup(tmp);
	if (ft_strchr(tmp, '\n') != 0)
	{
		// printf("1\n");
		tmp2 = ft_strjoin(str, f);
		// if (*tmp2 == '\0')
		// 	free(tmp2);
		// printf("tmp21 = %p\n", tmp2);
		// printf("tmp21 = %s", tmp2);
		s = malloc(ft_strlen(tmp2) + 2);
		// if (*tmp2 == '\0')
		// 	free(tmp2);
		if (!s)
			return (NULL);
		if (tmp2 != NULL)
			while (tmp2[i] != '\0')
			{
			s[i] = tmp2[i];
			i++;
			}
		s[i] = '\n';
		s[i + 1] = '\0';
		// printf("s = %zu", ft_strlen(s));
		free(f);
		free(str);
		free(tmp2);
		return (s);
	}
	else if (j == BUFFER_SIZE)
	{
		// printf("2\n");
		s = ft_strjoin(str, f);
		// printf("s = %p\n", s);
		free(f);
		free(str);
		return (s);
	}
	else if (j < BUFFER_SIZE && j != 0)
	{
		// printf("3\n");
		tmp2 = rest_less(f, j);
		// printf("tmp2 = %p\n", tmp2);
		s = ft_strjoin(str, tmp2);
		// printf("s = %p\n", s);
		free(tmp2);
		free(str);
		free(f);
		return (s);
	}
	// free(f);
	// free(str);
	// free(tmp);
	return (str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	len_check(char *s1, char *s2)
{
	int	len_1 = 0;
	int	len_2 = 0;
	int len = 0;
	if (s1 == NULL)
	{
		len_1 = 0;
		// printf("s2 l = %zu\n", ft_strlen(NULL));
		if (ft_strchr(s2, '\n') != 0)
		{
			// printf("fuccck me\n");
			len_2 = ft_strlen_limited_edition(s2);
			// printf("len = %d\n", len_2);
		}
		else
			len_2 = ft_strlen(s2);
	}
	else if (s2 == NULL)
	{
		len_2 = 0;
		len_1 = ft_strlen(s1);
	}
	else
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
	}
	len = len_1 + len_2;
	return (len);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char *str = NULL;
	int i = 0;
	int j = 0;
	int len = len_check(s1, s2);
	// printf("i = %d\n", len);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	// printf("s1 = %s\n", s1);
	// printf("s2 = %s\n", s2);
	if (s1 != NULL && len > 0)
		while (s1[i] != '\0')
			str[j++] = s1[i++];
	// printf("i = %d\n", i);
	i = 0;
	if (s2 != NULL && len > 0)
		while ((s2[i] != '\0' && s2[i] != '\n'))
			str[j++] = s2[i++];
	str[j] = '\0';
	if (*str == '\0')
	{
		free(str);
		return (NULL);
	}
	// printf("j = %c\n", str[j]);
	// free(s1);
	return (str);
}

int	ft_strchr(char *s, int c)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = (char ) c;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == tmp)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;
	size_t j = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	if (len > i)
		len = i;
	if (start > i)
	{
		new_string = malloc(sizeof(char) + 1);
		new_string[0] = 0;
		return (new_string);
	}
	new_string = malloc((len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (s[start] != '\0' && len-- > 0)
		new_string[j++] = s[start++];
	new_string[j] = '\0';
	return (new_string);
}