/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:30:54 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/26 18:09:53 by thbernar         ###   ########.fr       */
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
	while (p.y < app->winsize.y)
	{
		p.x = 0;
		while (p.x < app->winsize.x)
		{
			ft_calc_color(app, p);
			p.x++;
		}
		p.y++;
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

void	ft_calc_color(t_app *app, t_coord p)
{
	(void)app;
	(void)p;
}
