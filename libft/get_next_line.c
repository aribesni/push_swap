/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:21:10 by aribesni          #+#    #+#             */
/*   Updated: 2020/07/01 15:02:15 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_next_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char		*ft_line(char *line, char **str)
{
	char	*s1;

	if (ft_strchr(*str, '\n'))
	{
		if (!(line = ft_substr(*str, 0, ft_next_line(*str))))
			return (NULL);
		s1 = *str;
		if (!(*str = ft_substr(s1, ft_next_line(s1) + 1, ft_strlen(s1))))
			return (NULL);
		free(s1);
	}
	else
	{
		if (!(line = ft_strdup(*str)))
			return (NULL);
		free(*str);
		*str = NULL;
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	static char	*str = NULL;
	char		*keep;

	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 0;
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		keep = str;
		str = ft_strjoin(keep, buff);
		free(keep);
	}
	if ((ret == -1) || (!(*line = ft_line(*line, &str))))
		return (-1);
	if (!(str))
		return (0);
	return (1);
}
