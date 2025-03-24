/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:12:00 by ibkocak           #+#    #+#             */
/*   Updated: 2024/04/20 16:46:07 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countline(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free (line);
		i++;
		line = get_next_line(fd);
	}
	free (line);
	return (i);
}

void	mapcheck3(t_solong *solong)
{
	if (solong->pcount != 1 || solong->ccount < 1 || solong->ecount != 1)
		ft_ferror(solong);
	if (solong->mapx >= 41 || solong->mapy >= 22)
		ft_ferror(solong);
}

void	mapcheck2(t_solong	*solong, int y, int x)
{
	y = 0;
	while (y < solong->mapy)
	{
		x = 0;
		while (x < solong->mapx)
		{
			if (solong->map[y][x] == 'P')
			{
				solong->pcount += 1;
				solong->chrx = x;
				solong->chry = y;
			}
			if (solong->map[y][x] == 'E')
			{
				solong->ecount += 1;
				solong->e_x = x;
				solong->e_y = y;
			}
			if (solong->map[y][x] == 'C')
				solong->ccount += 1;
			x++;
		}
		y++;
	}
	mapcheck3(solong);
}

void	mapcheck(t_solong *solong)
{
	int	y;
	int	x;

	y = -1;
	while (++y < solong->mapy)
	{
		x = -1;
		while (++x < solong->mapx)
		{
			if ((y == 0 || y == solong->mapy - 1)
				|| (x == 0 || x == solong->mapx - 1))
			{
				if (solong->map[y][x] != '1')
					ft_ferror(solong);
			}
			if (!ft_strchr("10PEC", solong->map[y][x]))
				ft_ferror(solong);
		}
		if (solong->map[y][x] != '\0')
			ft_ferror(solong);
	}
	mapcheck2(solong, 0, 0);
}

void	ft_getmap(t_solong *solong, char *str)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	i = 0;
	solong->mapy = countline(fd);
	solong->map = malloc(sizeof(char *) * (solong->mapy + 1));
	if (!solong->map)
		return ;
	close(fd);
	open(str, O_RDONLY);
	while (i < solong->mapy)
	{
		solong->map[i] = get_next_line(fd);
		i++;
	}
	solong->map[i] = NULL;
	solong->mapx = ft_strlen(solong->map[0]);
	solong->ccount = 0;
	solong->ecount = 0;
	solong->pcount = 0;
	close(fd);
}
