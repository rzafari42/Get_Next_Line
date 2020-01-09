/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:59:50 by rzafari           #+#    #+#             */
/*   Updated: 2019/11/18 17:21:36 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	int			i;
	int			j;
	int			z;

	z = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(res = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	while (*s1)
		res[z++] = *(s1++);
	while (*s2)
		res[z++] = *(s2++);
	res[z] = '\0';
	return (res);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (s1[j] && j < i)
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	len = (j < n) ? j : n;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*s1 && i < len)
	{
		s2[i] = *(s1++);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = (int)size;
	if ((str = (char*)malloc(sizeof(char) * (i + 1))) == 0)
		return (NULL);
	while (i >= 0)
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

char		*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char*)s;
	while (*ptr && *ptr != c)
		ptr++;
	if (*ptr == c)
		return (ptr);
	else
		return (NULL);
}
