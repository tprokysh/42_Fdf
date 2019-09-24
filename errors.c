/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 09:53:18 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 18:19:59 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		color_error(void)
{
	ft_putstr("Wrong color or coordinate.\nExample: 0xFFFFFF.\n");
	exit(1);
	return (0);
}

int		filename_error(void)
{
	ft_putstr("Wrong file\nUsage: ./fdf [map_name]\n");
	exit(1);
	return (0);
}

int		file_error(void)
{
	ft_putstr("Invalid file.\nLenght != Width!\n");
	exit(1);
	return (0);
}

int		z_error(void)
{
	ft_putstr("Too big coordinate.\n");
	exit(1);
	return (0);
}

int		av_error(void)
{
	ft_putstr("Too much arguments.\nUsage: ./fdf [map_name]");
	exit(1);
	return (0);
}
