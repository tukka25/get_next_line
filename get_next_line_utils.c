/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:33:11 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/21 20:06:06 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joining(char *str, char *tmp, int j)
{
	t_vars	vars;

	vars.d = 0;
	vars.i = 0;
	vars.f = ft_strdup(tmp);
	if (ft_strlen_and_ft_strchr(tmp, '\n', 0) != 0)
	{
		vars.tmp2 = ft_strjoin(str, vars.f);
		vars.s = malloc(ft_strlen_and_ft_strchr(vars.tmp2, 0, 1) + 2);
		if (!vars.s)
			return (NULL);
		if (vars.tmp2 != NULL)
			while (vars.tmp2[vars.d] != '\0')
				vars.s[vars.i++] = vars.tmp2[vars.d++];
		vars.s[vars.i] = '\n';
		vars.s[vars.i + 1] = '\0';
		free(vars.tmp2);
	}
	else if (j == BUFFER_SIZE)
		vars.s = ft_strjoin(str, vars.f);
	else if (j < BUFFER_SIZE && j != 0)
	{
		vars.tmp2 = rest_less(vars.f, j);
		vars.s = ft_strjoin(str, vars.tmp2);
		free(vars.tmp2);
	}
	else
		return (free(vars.f), str);
	return (free(vars.f), free(str), vars.s);
}

size_t	ft_strlen_and_ft_strchr(char *str, int c, int n)
{
	char	tmp;
	size_t	i;

	i = -1;
	tmp = (char ) c;
	if (n == 1)
	{
		i = 0;
		if (!str || str == NULL)
			return (0);
		while (str[++i] != '\0')
			;
		return (i);
	}
	else
	{
		if (!str)
			return (0);
		while (str[++i] != '\0')
			if (str[i] == tmp)
				return (1);
		return (0);
	}
}

static int	len_check(char *s1, char *s2)
{
	int	len_1;
	int	len_2;
	int	len;

	len_1 = 0;
	len_2 = 0;
	if (s1 == NULL)
	{
		if (ft_strlen_and_ft_strchr(s2, '\n', 0) != 0)
			while (s2[len_2] && s2[len_2] != '\n')
				len_2++;
		else
			len_2 = ft_strlen_and_ft_strchr(s2, 0, 1);
	}
	else if (s2 == NULL)
		len_1 = ft_strlen_and_ft_strchr(s1, 0, 1);
	else
	{
		len_1 = ft_strlen_and_ft_strchr(s1, 0, 1);
		len_2 = ft_strlen_and_ft_strchr(s2, 0, 1);
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
	if (s1 != NULL && len > 0)
		while (s1[i] != '\0')
			str[j++] = s1[i++];
	i = 0;
	if (s2 != NULL && len > 0)
		while ((s2[i] != '\0' && s2[i] != '\n'))
			str[j++] = s2[i++];
	str[j] = '\0';
	if (*str == '\0')
		return (free(str), NULL);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;
	int		j;

	if (!s)
		return (NULL);
	i = ft_strlen_and_ft_strchr(s, 0, 1);
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
