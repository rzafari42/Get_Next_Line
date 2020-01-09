/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <rzafari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:59:28 by rzafari           #+#    #+#             */
/*   Updated: 2019/11/18 17:17:58 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char		*ft_newline(char **str)
{
	char	*buffer;
	char	*newline;
	char	*temp;

	buffer = ft_strchr(*str, '\n');
	temp = NULL;
	if (buffer)
	{
		if (!(newline = ft_strndup(*str, buffer - (*str))))
			return (NULL);
		temp = *str;
		if (!(*str = ft_strdup(buffer + 1)))
			return (NULL);
		free(temp);
	}
	else if (!(newline = ft_strdup(*str)))
		return (NULL);
	if (!(*str) || !temp)
	{
		free(*str);
		*str = NULL;
	}
	return (newline);
}

char		*ft_read(int fd, char *buffer, char **str)
{
	int		ret;
	char	*temp;

	ret = 1;
	temp = NULL;
	while ((ft_check(*str) == 0) && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		temp = *str;
		buffer[ret] = '\0';
		if (!(*str = ft_strjoin(*str, buffer)))
			return (NULL);
		free(temp);
	}
	free(buffer);
	return (*str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*buffer;
	char		*end;

	if (fd < 0 || (str == NULL && !(str = ft_strnew(0)))
		|| !(buffer = ft_strnew(BUFFER_SIZE + 1)) || BUFFER_SIZE < 1
		|| read(fd, buffer, 0) == -1 || !(*line = ft_strnew(0))
		|| !(ft_read(fd, buffer, &str)))
		return (-1);
	if (*str)
	{
		end = ft_strchr(str, '\n');
		free(*line);
		if (!(*line = ft_newline(&str)))
			return (-1);
		if (!end)
		{
			free(str);
			str = NULL;
			return (0);
		}
		return (1);
	}
	return (0);
}
