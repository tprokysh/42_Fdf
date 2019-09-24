/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:38:29 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 18:38:30 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_coord		*iso(t_coord *cd, t_coord *d, t_mlx *mlx)
{
	int i;
	int x_x;
	int y_y;

	i = -1;
	while (++i < mlx->d)
	{
		x_x = cd[i].x;
		y_y = cd[i].y;
		cd[i].x = (x_x - y_y) * cos(0.46365);
		cd[i].y = -d[i].z + (x_x + y_y) * sin(0.46365);
	}
	return (cd);
}

double		**rotation_matrix(double a, double b, double c)
{
	double	**m;
	int		i;

	i = -1;
	m = (double**)malloc(sizeof(double*) * 3);
	while (++i < 3)
		m[i] = (double*)malloc(sizeof(double) * 3);
	m[0][0] = 0.5 * (cos(b + c) + cos(b - c));
	m[0][1] = 0.5 * (sin(b - c) - sin(b + c));
	m[0][2] = sin(b);
	m[1][0] = 0.25 * (cos(a - b + c) - cos(a + b + c) -
			cos(a + b - c) + cos(a - b - c) + 2 * sin(a + c) - 2 * sin(a - c));
	m[1][1] = 0.25 * (2 * cos(a + c) + 2 * cos(a - c) +
			sin(a + b + c) - sin(-a + b + c) - sin(a - b + c) - sin(a + b - c));
	m[1][2] = 0.5 * (-sin(a + b) - sin(a - b));
	m[2][0] = 0.25 * (-2 * cos(a + c) + 2 * cos(a - c) - sin(a + b + c) -
			sin(-a + b + c) - sin(a + b - c) - sin(-a + b - c));
	m[2][1] = 0.25 * (-cos(a + b + c) - cos(-a + b + c) + cos(a - b + c) +
			cos(a + b - c) + 2 * sin(a + c) + 2 * sin(a - c));
	m[2][2] = 0.5 * (cos(a + b) + cos(a - b));
	return (m);
}

t_coord		*initialize_coord(t_coord *d, t_mlx *mlx)
{
	int		i;
	t_coord	*cd;
	double	**m;

	i = -1;
	cd = (t_coord*)malloc(sizeof(t_coord) * mlx->d);
	m = rotation_matrix(mlx->angle[0], mlx->angle[1], mlx->angle[2]);
	while (++i < mlx->d)
	{
		cd[i].x = (d[i].x * m[0][0] + d[i].y
				* m[1][0] + d[i].z * m[2][0]) * mlx->incr;
		cd[i].y = (d[i].x * m[0][1] + d[i].y
				* m[1][1] + d[i].z * m[2][1]) * mlx->incr;
		cd[i].z = (d[i].x * m[0][2] + d[i].y
				* m[1][2] + d[i].z * m[2][2]) * mlx->incr;
	}
	if (mlx->iso == 1)
		cd = iso(cd, d, mlx);
	cd = get_color_help(cd, d, mlx);
	i = -1;
	while (++i < 3)
		ft_memdel((void*)&m[i]);
	free(m);
	return (cd);
}

void		start(t_mlx *mlx)
{
	t_coord *point;
	int		i;

	i = 0;
	clear_image(mlx);
	point = initialize_coord(mlx->crd, mlx);
	draw(mlx, point, mlx->ln, i);
	ft_memdel((void*)&point);
}

void		initialize_mlx(t_mlx *mlx)
{
	mlx->angle[0] = (-176 * M_PI) / 180;
	mlx->angle[1] = (5 * M_PI) / 180;
	mlx->angle[2] = ((60 * M_PI) / 180) - 0.84;
	mlx->m[0] = mlx->win_w / 2;
	mlx->m[1] = mlx->win_h / 2;
	mlx->incr = (double)mlx->win_w / (mlx->map_w + mlx->map_h);
	start(mlx);
}
