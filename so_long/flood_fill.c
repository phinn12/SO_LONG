/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:12:23 by ibkocak           #+#    #+#             */
/*   Updated: 2024/04/20 16:18:52 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(char **tab, t_point size, int row, int col)
{
	if (row < 0 || col < 0)
		return ;
	if (row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == '8' || tab[row][col] == '1')
		return ;
	tab[row][col] = '8';
	f_fill(tab, size, row - 1, col);
	f_fill(tab, size, row + 1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	f_fill(tab, size, begin.y, begin.x);
}

void	ft_floodcheck(t_solong *solong)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if (ft_strchr("PEC", solong->mapcopy[y][x]))
				ft_error(solong);
			x++;
		}
		y++;
	}
}

void	ft_flood2(t_solong *solong)
{
	t_point	map;
	t_point	character;

	map.x = solong->mapx;
	map.y = solong->mapy;
	character.x = solong->chrx;
	character.y = solong->chry;
	flood_fill(solong->mapcopy, map, character);
	ft_floodcheck(solong);
}

void	ft_flood(t_solong *solong, char *str)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	solong->mapcopy = malloc(sizeof(char *) * (solong->mapy + 1));
	i = 0;
	while (i < solong->mapy)
	{
		solong->mapcopy[i] = get_next_line(fd);
		i++;
	}
	solong->mapcopy[i] = NULL;
	ft_flood2(solong);
}
