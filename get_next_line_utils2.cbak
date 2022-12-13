/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:14:12 by abdamoha          #+#    #+#             */
/*   Updated: 2022/12/05 18:14:17 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin_original(char const *s1, char const *s2)
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
		while (s2[i] != '\0')
			str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}