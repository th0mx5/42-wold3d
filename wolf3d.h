/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:11:44 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/28 22:44:25 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_coord_d
{
	double		x;
	double		y;
}				t_coord_d;

typedef struct	s_app
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*fname;
	t_coord		winsize;
	char		*img_data;
	double		vector;
	t_coord		pos;
	t_coord		mouse;
	t_coord		map_size;
	int			**map;
}				t_app;

int				ft_keyhooked(int keycode, t_app *app);
int				ft_zoom(int keycode, t_app *app, int x, int y);
int				ft_mousehooked(int button, int x, int y, t_app *app);
int				ft_hook(int x, int y, t_app *app);

void			ft_win_draw(t_app *app);
void			ft_img_putpixel(t_app *app, t_coord p, int *color);
void			ft_calc_color(t_app *app, t_coord p);

void			ft_app_init(t_app *app);
void			ft_app_countmap(t_app *app);
void			ft_app_allocmap(t_app *app);
void			ft_app_writemap(t_app *app);

void			ft_printcontrols(void);
void			ft_error(char *s);
void			ft_pickcolors(t_app *app, int *color, int i);

double			ft_abs_d(double nb);
int				ft_abs(int nb);
void			ft_free_strsplit(char **array);

#endif
