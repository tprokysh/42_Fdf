/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:26:15 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 17:17:08 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	mouse_not_move(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == 1)
		mlx->click = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->click == 1 && (x > 0 && x < mlx->win_w)
	&& (y > 0 && y < mlx->win_h))
	{
		if (x > mlx->mouse[0])
			mlx->angle[1] += 0.02;
		if (x < mlx->mouse[0])
			mlx->angle[1] -= 0.02;
		if (y > mlx->mouse[1])
			mlx->angle[0] -= 0.02;
		if (y < mlx->mouse[1])
			mlx->angle[0] += 0.02;
		mlx->mouse[0] = x;
		mlx->mouse[1] = y;
		start(mlx);
	}
	return (0);
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	if (button == 5)
		mlx->incr += 0.3;
	if (button == 4)
	{
		if (mlx->incr > 1)
			mlx->incr -= 0.3;
	}
	if (button == 1)
	{
		mlx->mouse[0] = x;
		mlx->mouse[1] = y;
		mlx->click = 1;
		mouse_move(x, y, mlx);
	}
	start(mlx);
	return (0);
}
