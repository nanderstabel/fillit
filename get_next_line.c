/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bwaarle <bwaarle@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/20 14:01:19 by bwaarle        #+#    #+#                */
/*   Updated: 2019/06/17 14:31:37 by bwaarle       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_line(const int fd, char **s, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (s[fd][i] != '\0')
	{
		if (s[fd][i] == '\n')
		{
			*line = ft_strsub(s[fd], 0, i);
			tmp = ft_strdup(s[fd] + i + 1);
			free(s[fd]);
			s[fd] = tmp;
			return (1);
		}
		i++;
	}
	if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char *s[1024];

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		buf[ret] = '\0';
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	if (ft_line(fd, s, line) == 1)
		return (1);
	return (0);
}
