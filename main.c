/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:41:24 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 17:17:33 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	clear_image(t_mlx *mlx)
{
	ft_bzero(mlx->buff, (size_t)mlx->win_w * mlx->win_h * mlx->bpp);
}

void	menu(t_mlx *mlx)
{
	mlx->win_ptr2 = mlx_new_window(mlx->mlx_ptr, mlx->win_h / 2, mlx->win_w / 2,
			"Fdf menu");
	mlx->img_ptr2 = mlx_new_image(mlx->mlx_ptr, mlx->win_w, mlx->win_h);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr2, mlx->img_ptr2, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 190, 0, 0xFFFFFF,
			"Instructions");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 30, 0xFFFFFF,
			"Exit -> ESC");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 60, 0xFFFFFF,
			"Move -> Arrows");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 90, 0xFFFFFF,
			"Angles -> WASD & QE & Mouse");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 120, 0xFFFFFF,
			"Projection -> I(isometric) & P(parallel)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 150, 0xFFFFFF,
			"Increase Z-coordinate -> -+");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr2, 20, 180, 0xFFFFFF,
			"Zoom -> Mouse wheel");
}

void	make(t_mlx *mlx)
{
	int size_line;
	int endian;

	mlx->win_h = 1000;
	mlx->win_w = 1000;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_h, mlx->win_w, "FdF");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_w, mlx->win_h);
	mlx->buff = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &size_line, &endian);
	menu(mlx);
	mlx->bpp /= 8;
	initialize_mlx(mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_events, mlx);
	mlx_hook(mlx->win_ptr2, 2, 0, key_events, mlx);
	mlx_hook(mlx->win_ptr, 4, 1, mouse_events, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_not_move, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_mlx	*mlx;
	int		fd;
	int		i;

	if (ac == 2)
	{
		mlx = (t_mlx *)malloc(sizeof(t_mlx));
		mlx->ln = (t_line *)malloc(sizeof(t_line));
		if ((fd = open(av[1], O_RDONLY)) < 0)
			filename_error();
		counter(fd, mlx);
		mlx->crd = reader(av[1], mlx->d);
		i = -1;
		while (++i < mlx->d)
		{
			mlx->crd[i].x = mlx->crd[i].x - mlx->map_w / 2;
			mlx->crd[i].y = mlx->map_h / 2 - mlx->crd[i].y;
		}
		make(mlx);
	}
	else
		av_error();
	return (0);
}
