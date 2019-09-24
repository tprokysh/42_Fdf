/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:11:33 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 17:21:37 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		k_project(int keycode, t_mlx *mlx)
{
	mlx->angle[0] = (-176 * M_PI) / 180;
	mlx->angle[1] = (5 * M_PI) / 180;
	if (keycode == 34)
	{
		mlx->angle[2] = (60 * M_PI) / 180;
		mlx->iso = 1;
	}
	if (keycode == 35)
	{
		mlx->angle[2] = ((60 * M_PI) / 180) - 0.84;
		mlx->iso = 0;
	}
	return (0);
}

int		k_move(int keycode, t_mlx *mlx)
{
	if (keycode == 124)
		mlx->m[0] += 10;
	if (keycode == 123)
		mlx->m[0] -= 10;
	if (keycode == 126)
		mlx->m[1] -= 10;
	if (keycode == 125)
		mlx->m[1] += 10;
	return (0);
}

int		k_depth(int keycode, t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->d)
	{
		if (mlx->crd[i].z > 0 || mlx->crd[i].z < 0)
		{
			if (keycode == 27)
			{
				if ((mlx->crd[i].z - 1) == 0)
					mlx->crd[i].z -= 2;
				else
					mlx->crd[i].z -= 1;
			}
			if (keycode == 24)
			{
				if ((mlx->crd[i].z + 1) == 0)
					mlx->crd[i].z += 2;
				else
					mlx->crd[i].z += 1;
			}
		}
	}
	return (0);
}

int		k_rotation(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->angle[0] += 0.12;
	if (keycode == 1)
		mlx->angle[0] -= 0.12;
	if (keycode == 2)
		mlx->angle[1] += 0.12;
	if (keycode == 0)
		mlx->angle[1] -= 0.12;
	if (keycode == 14)
		mlx->angle[2] -= 0.12;
	if (keycode == 12)
		mlx->angle[2] += 0.12;
	return (0);
}

int		key_events(int keycode, t_mlx *mlx)
{
	k_rotation(keycode, mlx);
	k_move(keycode, mlx);
	k_depth(keycode, mlx);
	if (keycode == 34 || keycode == 35)
		k_project(keycode, mlx);
	if (keycode == 53)
		exit(0);
	start(mlx);
	return (0);
}
