/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:11 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/10 21:54:47 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	len_check(char const *s1, char const *s2)
{
	int	len_1;
	int	len_2;
	int	len;

	len_1 = 0;
	len_2 = 0;
	if (s1 == NULL)
	{
		len_1 = 0;
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
	int		len;
	char	*str;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = len_check(s1, s2);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	if (s1 != NULL)
		while (s1[i] != '\0')
			str[j++] = s1[i++];
	i = 0;
	if (s2 != NULL)
		while ((s2[i] != '\0' && s2[i] != '\n'))
			str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;
	int		j;

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
