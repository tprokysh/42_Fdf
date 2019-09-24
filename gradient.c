/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:34:04 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 17:20:46 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		get_light(int from, int to, double percent)
{
	return ((int)((1 - percent) * from + percent * to));
}

double	percentt(int from, int to, int cur)
{
	double	placement;
	double	distance;

	placement = cur - from;
	distance = to - from;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		color(int color, int s_color, t_line *l)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (color == s_color)
		return (color);
	if (l->dx > l->dy)
		percent = percentt(l->x1, l->x2, l->x);
	else
		percent = percentt(l->y1, l->y2, l->y);
	red = get_light((color >> 16) & 0xFF, (s_color >> 16) & 0xFF, percent);
	green = get_light((color >> 8) & 0xFF, (s_color >> 8) & 0xFF, percent);
	blue = get_light(color & 0xFF, s_color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
