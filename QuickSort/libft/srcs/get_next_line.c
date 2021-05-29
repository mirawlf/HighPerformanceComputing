/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samymone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:27:44 by samymone          #+#    #+#             */
/*   Updated: 2019/06/04 15:38:41 by samymone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	returned_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, i)))
			return (-1);
		tmp = ft_strsub(s[fd], i + 1, ft_strlen(s[fd]));
		ft_strdel(&s[fd]);
		s[fd] = ft_strsub(tmp, 0, ft_strlen(tmp));
		ft_strdel(&tmp);
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][i] == '\0')
	{
		if (!(*line = ft_strsub(s[fd], 0, i)))
			return (-1);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			free_func(char **s, int fd)
{
	free(s[fd]);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[10240];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > 10240)
		return (-1);
	s[fd] = (s[fd] == NULL) ? ft_strnew(0) : s[fd];
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = s[fd];
		if (!(s[fd] = ft_strjoin(s[fd], buf)))
			return (free_func(s, fd));
		free(tmp);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (returned_line(s, line, fd));
}
