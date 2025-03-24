/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:52:24 by ibkocak           #+#    #+#             */
/*   Updated: 2024/04/20 17:25:28 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_zero(t_solong *solong)
{
	solong->ccount = 0;
	solong->c_number = 0;
	solong->chrx = 0;
	solong->chry = 0;
	solong->mapy = 0;
	solong->mapx = 0;
	solong->pcount = 0;
	solong->ecount = 0;
	solong->moves_number = 0;
}

int	main(int ac, char **av)
{
	t_solong	solong;

	solong.mlx = mlx_init();
	ft_zero(&solong);
	ft_getmap(&solong, av[1]);
	mapcheck(&solong);
	ft_flood(&solong, av[1]);
	solong.mlx_win = mlx_new_window(solong.mlx,
			solong.mapx * 64, solong.mapy * 64, "so_long");
	imageup(&solong);
	add_image(&solong);
	mlx_hook(solong.mlx_win, 2, 0, key_hook, &solong);
	mlx_hook(solong.mlx_win, 17, 0, ft_game_closed, &solong);
	mlx_loop(solong.mlx);
}
