/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/10 20:33:59 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_win_draw(t_app *app)
{
	t_coord	p;
	int		n[3];

	p.x = 0;
	p.y = 0;
	app->img = mlx_new_image(app->win, app->winsize.x, app->winsize.y);
	app->img_data = mlx_get_data_addr(app->img, &n[0], &n[1], &n[2]);
	while (p.x < app->winsize.x)
	{
		ft_calc_color(app, p);
		p.x++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	mlx_destroy_image(app->mlx, app->img);
	mlx_do_sync(app->mlx);
}

void	ft_img_putpixel(t_app *app, t_coord p, int *color)
{
	int i;

	i = (p.x + (p.y * app->winsize.x)) * 4;
	if (p.x > -1 && p.y > -1 && p.x < app->winsize.x && p.y < app->winsize.y)
	{
		app->img_data[i] = (char)color[0];
		app->img_data[i + 1] = (char)color[1];
		app->img_data[i + 2] = (char)color[2];
	}
}

void	ft_calc_color(t_app *app, t_coord p) // CALL RAYCASTING
{
	int color[3];
	int distance_player_projscreen = (app->winsize.x / 2 / tan(app->fov / 2));
	//int angle_between_rays = app->fov / app->winsize.x;
	t_coord A;
	t_coord C;
	int Ya = -64;
	int Xa = 64 / tan(app->fov);
	int PA;
	A.y = (int)(app->pos.y / 64) * 64 - 1;
	A.x = app->pos.x + (app->pos.y - A.y) / tan(app->fov);
	C.x = A.x;
	C.y = A.y;
	while (app->map[C.x / 64][C.y / 64] == 0)
	{
		C.x = C.x + Xa;
		C.y = C.y + Ya;
	}
	PA = ft_abs(app->pos.x - C.x) / cos(app->fov);
	int wall_height = 64 / PA * distance_player_projscreen;
	color[0] = 0;
	color[1] = 255;
	color[2] = 0;
	p.y = (app->winsize.y / 2) - (wall_height / 2);
	while (p.y < (app->winsize.y / 2) + (wall_height / 2))
	{
		ft_img_putpixel(app, p, color);
		p.y++;;
	}
}
