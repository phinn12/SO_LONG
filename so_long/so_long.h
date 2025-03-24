/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:56:34 by ibkocak           #+#    #+#             */
/*   Updated: 2024/02/26 18:18:05 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_img
{
	void	*exit;
	void	*wall;
	void	*phinn;
	void	*coin;
	void	*floor;
}	t_img;

typedef struct s_solong
{
	char	**map;
	char	**mapcopy;
	int		mapy;
	int		mapx;
	int		chrx;
	int		chry;
	int		pcount;
	int		ecount;
	int		ccount;
	void	*mlx;
	void	*mlx_win;
	t_img	*img;
	int		moves_number;
	int		c_number;
	int		e_x;
	int		e_y;
}	t_solong;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);
void	ft_flood(t_solong *solong, char *str);
void	ft_flood2(t_solong *solong);
void	ft_getmap(t_solong *solong, char *str);
void	mapcheck(t_solong *solong);
void	setimage2(t_solong *solong, int x, int y);
void	setimage3(t_solong *solong, int x, int y);
void	add_image(t_solong *solong);
void	imageup(t_solong *solong);
void	keycode_2(t_solong *movement, int x, int y);
void	keycode_0(t_solong *movement, int x, int y);
void	keycode_13(t_solong *movement, int x, int y);
void	keycode_1(t_solong *movement, int x, int y);
int		key_hook(int keycode, t_solong *movement);
void	ft_ferror(t_solong *solong);
void	ft_zero(t_solong *solong);
int		ft_game_closed(t_solong *solong);
void	ft_error(t_solong *solong);
void	ft_win(t_solong *solong);
void	ft_floodcheck(t_solong *solong);
void	mapcheck2(t_solong	*solong, int y, int x);
void	mapcheck3(t_solong *solong);

#endif