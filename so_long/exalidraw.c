/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exalidraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:36:28 by ibkocak           #+#    #+#             */
/*   Updated: 2024/02/26 18:15:26 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imageup(t_solong *solong)
{
	int	x;
	int	y;

	solong->img = malloc(sizeof(t_img));
	solong->img->coin = mlx_xpm_file_to_image(solong->mlx,
			"textures/coin.xpm", &x, &y);
	solong->img->exit = mlx_xpm_file_to_image(solong->mlx,
			"textures/exit.xpm", &x, &y);
	solong->img->phinn = mlx_xpm_file_to_image(solong->mlx,
			"textures/phinn.xpm", &x, &y);
	solong->img->wall = mlx_xpm_file_to_image(solong->mlx,
			"textures/wall.xpm", &x, &y);
	solong->img->floor = mlx_xpm_file_to_image(solong->mlx,
			"textures/floor.xpm", &x, &y);
	if (!solong->img->coin || !solong->img->floor
		|| !solong->img->wall || !solong->img->phinn || !solong->img->exit)
		ft_ferror(solong);
}

void	setimage2(t_solong *solong, int x, int y)
{
	if (solong->map[solong->e_y][solong->e_x] == '0')
		solong->map[solong->e_y][solong->e_x] = 'E';
	if (solong->map[y][x] == '1')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->wall, x * 64, y * 64);
	if (solong->map[y][x] == '0')
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->floor, x * 64, y * 64);
	if (solong->map[y][x] == 'P')
	{
		setimage3(solong, x, y);
	}
	if (solong->map[y][x] == 'E')
	{
		setimage3(solong, x, y);
	}
	if (solong->map[y][x] == 'C')
	{
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->floor, x * 64, y * 64);
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->coin, x * 64, y * 64);
	}
}

void	setimage3(t_solong *solong, int x, int y)
{
	if (solong->map[y][x] == 'P')
	{
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->floor, x * 64, y * 64);
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->phinn, x * 64, y * 64);
	}
	if (solong->map[y][x] == 'E')
	{
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->floor, x * 64, y * 64);
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->img->exit, x * 64, y * 64);
	}
}

void	add_image(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->mapy)
	{
		x = -1;
		while (++x <= solong->mapx)
		{
			if (solong->map[y][x] == '1')
				setimage2(solong, x, y);
			if (solong->map[y][x] == '0')
				setimage2(solong, x, y);
			if (solong->map[y][x] == 'P')
				setimage2(solong, x, y);
			if (solong->map[y][x] == 'C')
				setimage2(solong, x, y);
			if (solong->map[y][x] == 'E')
				setimage2(solong, x, y);
		}
		y++;
	}
}
