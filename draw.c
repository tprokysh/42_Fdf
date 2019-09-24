/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:33:19 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 17:16:48 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	put_image(t_mlx *mlx, int x, int y, int color)
{
	if ((x > 0 && x < mlx->win_w) && (y > 0 && y < mlx->win_h))
		*(int *)(mlx->buff + ((mlx->win_w * y + x) * mlx->bpp)) = color;
}

void	drawline2(t_line *l, t_mlx *mlx)
{
	l->x = l->x1;
	l->y = l->y1;
	l->d = -l->ly;
	l->l++;
	while (l->l--)
	{
		put_image(mlx, l->x, l->y, color(l->color, l->s_color, l));
		l->y += l->dy;
		l->d += 2 * l->lx;
		if (l->d > 0)
		{
			l->d -= 2 * l->ly;
			l->x += l->dx;
		}
	}
}

void	drawline1(t_line *l, t_mlx *mlx)
{
	l->x = l->x1;
	l->y = l->y1;
	l->d = -l->lx;
	l->l++;
	while (l->l--)
	{
		put_image(mlx, l->x, l->y, color(l->color, l->s_color, l));
		l->x += l->dx;
		l->d += 2 * l->ly;
		if (l->d > 0)
		{
			l->d -= 2 * l->lx;
			l->y += l->dy;
		}
	}
}

void	drawline(int f_color, int s_color, t_line *l, t_mlx *mlx)
{
	mlx->ln->color = f_color;
	mlx->ln->f_color = f_color;
	mlx->ln->s_color = s_color;
	l->dx = (l->x2 - l->x1 >= 0 ? 1 : -1);
	l->dy = (l->y2 - l->y1 >= 0 ? 1 : -1);
	l->lx = abs(l->x2 - l->x1);
	l->ly = abs(l->y2 - l->y1);
	l->l = ft_max(l->lx, l->ly);
	l->color = l->f_color;
	if (l->ly <= l->lx)
		drawline1(l, mlx);
	else
		drawline2(l, mlx);
}

void	draw(t_mlx *m, t_coord *p, t_line *l, int i)
{
	i = 0;
	while (i < m->d)
	{
		l->x1 = p[i].x + m->m[0];
		(m->d > 1 ? l->x2 = p[i + 1].x + m->m[0]
				: (l->x2 = p[i].x + m->m[0]));
		l->y1 = p[i].y + m->m[1];
		(m->d > 1 ? l->y2 = p[i + 1].y + m->m[1]
				: (l->y2 = p[i].y + m->m[1]));
		drawline(p[i].color, p[i].color, l, m);
		i++;
		if ((i + 1) % m->map_w == 0)
			i++;
	}
	i = 0;
	while (i + m->map_w < m->d)
	{
		l->x1 = p[i].x + m->m[0];
		l->x2 = p[i + m->map_w].x + m->m[0];
		l->y1 = p[i].y + m->m[1];
		l->y2 = p[i + m->map_w].y + m->m[1];
		drawline(p[i].color, p[i + m->map_w].color, l, m);
		i++;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}
