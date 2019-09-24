/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:00:02 by tprokysh          #+#    #+#             */
/*   Updated: 2018/11/14 11:12:03 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	create_line(char **line, char **tab, int fd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tab[fd][++i])
		if (tab[fd][i] == '\n')
			break ;
	*line = ft_strsub(tab[fd], 0, i);
	if (i < (int)ft_strlen(tab[fd]))
	{
		tmp = tab[fd];
		tab[fd] = ft_strdup(tmp + i + 1);
		free(tmp);
	}
	else
		ft_strclr(tab[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		*tab[OPEN_MAX];
	char			*save;

	if ((BUFF_SIZE < 1 || fd < 0 || line == NULL || read(fd, 0, 0) < 0))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!tab[fd])
			tab[fd] = ft_strnew(0);
		save = tab[fd];
		tab[fd] = ft_strjoin(save, buf);
		free(save);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == 0 && (tab[fd] == NULL || tab[fd][0] == '\0'))
		return (0);
	return (create_line(line, tab, fd));
}
