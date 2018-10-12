/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/12 22:43:20 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_win_draw(t_app *app)
{
	int		x;
	int		n[3];

	x = 0;
	app->img = mlx_new_image(app->win, app->winsize.x, app->winsize.y);
	app->img_data = mlx_get_data_addr(app->img, &n[0], &n[1], &n[2]);
	while (x < app->winsize.x)
	{
		ft_raycasting(app, x);
		x++;
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

void	ft_raycasting(t_app *app, int x) // CALL RAYCASTING
{
	printf("(%lf, %lf)\n", app->pos.x / 64, app->pos.y / 64);
	int color[3];
	int distance_player_projscreen = (app->winsize.x / 2) / tan(0.52);
	double  angle_between_rays = (double)app->fov / (double)app->winsize.x;
	t_coord A;
	t_coord B;
	int Ya = -64;
	int Xa = 64 / tan(1.04);
	int PA = 0;
	int PB = 0;
	int wall_height = 0;
	A.y = (int)(app->pos.y / 64) * 64 - 1;
	A.x = app->pos.x + (app->pos.y - A.y) / tan(1.04);
	if (x < app->winsize.x / 2)
		B.x = (int)(app->pos.x / 64) * 64 - 1;
	else
		B.x = (int)(app->pos.x / 64) * 64 + 64;
	B.y = app->pos.y + (app->pos.x - B.x) * tan(1.04);
	while (app->map[A.x / 64][A.y / 64] == 0) // HORIZONTAL
	{
		A.x = A.x + Xa;
		A.y = A.y + Ya;
	}
	while (app->map[B.x / 64][B.y / 64] == 0) // VERTICAL
	{
		B.x = B.x + Xa;
		B.y = B.y + Ya;
	}
	PA = sqrt((app->pos.x - A.x) * (app->pos.x - A.x) + (app->pos.y - A.y) * (app->pos.y - A.y));
	PB = sqrt((app->pos.x - B.x) * (app->pos.x - B.x) + (app->pos.y - B.y) * (app->pos.y - B.y));
	if (PA < PB)
		wall_height = 64 * distance_player_projscreen / PA;
	else
		wall_height = 64 * distance_player_projscreen / PB;

	printf("PA = %d, DPS = %d, wall = %d\n, angle = %lf", PA, distance_player_projscreen, wall_height, angle_between_rays);
	printf("PB = %d, DPS = %d, wall = %d\n", PB, distance_player_projscreen, wall_height);
	color[0] = 0;
	color[1] = 255;
	color[2] = 0;
	A.x = x;
	A.y = (app->winsize.y / 2) - (wall_height / 2);
	while (A.y < (app->winsize.y / 2) + (wall_height / 2))
	{
		ft_img_putpixel(app, A, color);
		A.y++;
	}
}
