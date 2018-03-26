/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/26 20:45:14 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_app_init(t_app *app)
{
	app->winsize.x = 720;
	app->winsize.y = 480;
	ft_app_allocmap(app);
}

void	ft_app_allocmap(t_app *app)
{
	int		fd[3];
	int		count;
	char	*s;

	fd[0] = 0;
	if (((fd[0] = open("map.wolf", O_RDONLY)) > 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd[0], &s)) > 0)
	{
		
	}
}
