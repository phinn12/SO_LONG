/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:57:54 by ibkocak           #+#    #+#             */
/*   Updated: 2024/02/26 17:18:57 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ferror(t_solong *solong)
{
	int	i;

	i = 0;
	ft_printf("Map Error\n");
	while (solong->map[i])
		free(solong->map[i++]);
	free(solong->map);
	exit(1);
}

int	ft_game_closed(t_solong *solong)
{
	int	i;

	i = 0;
	ft_printf("game closed!\n");
	while (solong->map[i])
	{
		free(solong->map[i]);
		i++;
	}
	free(solong->map);
	exit(1);
}

void	ft_error(t_solong *solong)
{
	int	i;

	i = 0;
	ft_printf("MAP ERROR!\n");
	while (solong->mapcopy[i])
	{
		if (solong->mapcopy[i] != NULL)
		{
			free(solong->mapcopy[i]);
			free(solong->map[i]);
		}
		i++;
	}
	free(solong->mapcopy);
	free(solong->map);
	exit(1);
}

void	ft_win(t_solong *solong)
{
	int	i;

	i = 0;
	ft_printf("CONGRATULATIONS\n");
	while (solong->map[i])
	{
		if (solong->map[i] != NULL)
			free(solong->map[i]);
		i++;
	}
	free(solong->map);
	exit(1);
}
