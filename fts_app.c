/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/03/28 22:48:05 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_app_init(t_app *app)
{
	app->winsize.x = 720;
	app->winsize.y = 480;
	ft_app_countmap(app);
	ft_app_allocmap(app);
	ft_app_writemap(app);
}

void	ft_app_countmap(t_app *app)
{
	int		fd;
	int		count[3];
	char	*s;
	char	**array;

	count[2] = 0;
	count[0] = 0;
	if (((fd = open("map.wolf", O_RDONLY)) < 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd, &s)) > 0)
	{
		array = ft_strsplit(s, ' ');
		free(s);
		count[1] = 0;
		while (array[count[1]])
			count[1]++;
		if (count[1] > count[2])
			count[2] = count[1];
		ft_free_strsplit(array);
		count[0]++;
	}
	app->map_size.x = count[2];
	app->map_size.y = count[0];
}

void	ft_app_allocmap(t_app *app)
{
	int i;

	i = 0;
	app->map = (int**)malloc(sizeof(int) * app->map_size.y);
	if (app->map == NULL)
		exit(-1);
	while (i < app->map_size.y)
	{
		app->map[i] = (int*)malloc(sizeof(int) * app->map_size.x);
		if (app->map[i] == NULL)
			exit(-1);
		i++;
	}
}

void	ft_app_writemap(t_app *app)
{
	int		fd;
	int		i;
	int		j;
	char	**array;
	char	*s;

	i = 0;
	if (((fd = open("map.wolf", O_RDONLY)) < 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd, &s)) > 0 && i < app->map_size.y)
	{
		j = 0;
		array = ft_strsplit(s, ' ');
		free(s);
		while (j < app->map_size.x)
		{
			if (array[j])
				app->map[i][j] = ft_atoi(array[j]);
			else
				app->map[i][j] = 0;
			j++;
		}
		ft_free_strsplit(array);
		i++;
	}
}
