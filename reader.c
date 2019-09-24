/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:31:57 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/12 20:14:09 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_coord		*get_color_help(t_coord *cd, t_coord *d, t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->d)
	{
		cd[i].color = d[i].color;
		if (cd[i].color == 0)
		{
			if (d[i].z < 0)
				cd[i].color = 0x1E43FC;
			if (d[i].z == 0)
				cd[i].color = 0xFFFFFF;
			if (d[i].z > 0)
				cd[i].color = 0xEB3434;
		}
	}
	return (cd);
}

int			check_str(char *tmp)
{
	int i;

	i = 0;
	if (ft_atoi(tmp) > 1000)
		z_error();
	if (tmp[i] == '-' || tmp[i] == '+')
		i++;
	while (tmp[i] && tmp[i] != ',')
	{
		if (!(ft_isdigit(tmp[i])))
			return (0);
		i++;
	}
	return (1);
}

int			get_line(char *l, int ls, t_coord *d, int c)
{
	char	**read;
	int		i;

	i = 0;
	read = ft_strsplit(l, ' ');
	while (read[i])
	{
		if (check_str(read[i]) == 0)
			color_error();
		d[c].x = i;
		d[c].y = ls;
		d[c].z = ft_atoi(read[i]);
		d[c].color = ft_atoi_hex(read[i]);
		c++;
		ft_strdel(&read[i]);
		i++;
	}
	free(read);
	return (c);
}

t_coord		*reader(char *av, int s)
{
	int		lines;
	int		count_lines;
	char	*line;
	t_coord	*dots;
	int		fd;

	lines = 0;
	count_lines = 0;
	dots = (t_coord *)malloc(sizeof(t_coord) * s);
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		lines = get_line(line, count_lines, dots, lines);
		free(line);
		count_lines++;
	}
	close(fd);
	return (dots);
}

void		counter(int fd, t_mlx *mlx)
{
	char	*line;
	char	**str;
	int		i;

	mlx->map_w = 0;
	mlx->map_h = 0;
	mlx->d = 0;
	while (get_next_line(fd, &line))
	{
		i = -1;
		str = ft_strsplit(line, ' ');
		while (str[++i])
			ft_strdel(&str[i]);
		if (mlx->map_w == 0)
			mlx->map_w = i;
		else if (i != mlx->map_w)
			file_error();
		mlx->d += i;
		mlx->map_h++;
		free(str);
		free(line);
	}
	close(fd);
}
