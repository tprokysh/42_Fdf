/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:40:03 by tprokysh          #+#    #+#             */
/*   Updated: 2018/11/29 17:40:05 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_coord;

typedef struct		s_line
{
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				d;
	int				lx;
	int				ly;
	int				l;
	int				color;
	int				f_color;
	int				s_color;
}					t_line;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*win_ptr2;
	void			*img_ptr;
	void			*img_ptr2;
	char			*buff;
	int				bpp;
	int				win_h;
	int				win_w;
	int				map_h;
	int				map_w;
	int				d;
	double			angle[3];
	double			incr;
	int				m[2];
	int				f;
	int				mouse[2];
	int				click;
	int				iso;
	t_coord			*crd;
	t_line			*ln;
}					t_mlx;

int					color_error(void);
int					filename_error(void);
int					file_error(void);
int					get_line(char *l, int ls, t_coord *d, int c);
int					check_str(char *tmp);
int					get_light(int from, int to, double percent);
int					color(int color, int s_color, t_line *l);
int					z_error(void);
int					av_error(void);
int					key_events(int keycode, t_mlx *mlx);
int					mouse_events(int keycode, int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_not_move(int button, int x, int y, t_mlx *mlx);
void				counter(int fd, t_mlx *mlx);
void				start(t_mlx *mlx);
void				menu(t_mlx *mlx);
void				make(t_mlx *mlx);
void				clear_image(t_mlx *mlx);
void				draw(t_mlx *mlx, t_coord *point, t_line *l, int i);
void				drawline(int f_color, int s_color, t_line *l, t_mlx *mlx);
void				drawline1(t_line *l, t_mlx *mlx);
void				drawline2(t_line *l, t_mlx *mlx);
void				initialize_mlx(t_mlx *mlx);
double				percentt(int from, int to, int cur);
t_coord				*get_color_help(t_coord *cd, t_coord *d, t_mlx *mlx);
t_coord				*reader(char *av, int s);
t_coord				*initialize_coord(t_coord *d, t_mlx *mlx);

#endif
