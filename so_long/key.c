/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:17:12 by ibkocak           #+#    #+#             */
/*   Updated: 2024/04/20 17:04:38 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keycode_2(t_solong *movement, int x, int y)
{
	movement->moves_number += 1;
	ft_printf("moves_number : %d\n", movement->moves_number);
	if (movement->map[y][x + 1] == '0' || movement->map[y][x + 1] == 'C')
	{
		if (movement->map[y][x + 1] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y][x + 1] = 'P';
		movement->chrx++;
	}
	if (movement->map[y][x + 1] == 'E')
	{
		if (movement->ccount == movement->c_number)
		{
			ft_win(movement);
		}
		else
		{
			movement->map[y][x] = '0';
			movement->map[y][x + 1] = 'P';
			movement->chrx++;
		}
	}
}

void	keycode_0(t_solong *movement, int x, int y)
{
	movement->moves_number += 1;
	ft_printf("moves_number : %d\n", movement->moves_number);
	if (movement->map[y][x - 1] == '0' || movement->map[y][x - 1] == 'C')
	{
		if (movement->map[y][x - 1] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y][x - 1] = 'P';
		movement->chrx--;
	}
	if (movement->map[y][x - 1] == 'E')
	{
		if (movement->ccount == movement->c_number)
		{
			ft_win(movement);
		}
		else
		{
			movement->map[y][x] = '0';
			movement->map[y][x - 1] = 'P';
			movement->chrx--;
		}
	}
}

void	keycode_13(t_solong *movement, int x, int y)
{
	movement->moves_number += 1;
	ft_printf("moves_number : %d\n", movement->moves_number);
	if (movement->map[y - 1][x] == '0' || movement->map[y - 1][x] == 'C')
	{
		if (movement->map[y - 1][x] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y - 1][x] = 'P';
		movement->chry--;
	}
	if (movement->map[y - 1][x] == 'E')
	{
		if (movement->ccount == movement->c_number)
		{
			ft_win(movement);
		}
		else
		{
			movement->map[y][x] = '0';
			movement->map[y - 1][x] = 'P';
			movement->chry--;
		}
	}
}

void	keycode_1(t_solong *movement, int x, int y)
{
	movement->moves_number += 1;
	ft_printf("moves_number : %d\n", movement->moves_number);
	if (movement->map[y + 1][x] == '0' || movement->map[y + 1][x] == 'C')
	{
		if (movement->map[y + 1][x] == 'C')
			movement->c_number++;
		movement->map[y][x] = '0';
		movement->map[y + 1][x] = 'P';
		movement->chry++;
	}
	if (movement->map[y + 1][x] == 'E')
	{
		if (movement->ccount == movement->c_number)
		{
			ft_win(movement);
		}
		else
		{
			movement->map[y][x] = '0';
			movement->map[y + 1][x] = 'P';
			movement->chry++;
		}
	}
}

int	key_hook(int keycode, t_solong *movement)
{
	int	x;
	int	y;

	x = movement->chrx;
	y = movement->chry;
	if (keycode == 53)
		ft_game_closed(movement);
	if (keycode == 2 && movement->map[y][x + 1] != '1')
		keycode_2(movement, x, y);
	if (keycode == 0 && movement->map[y][x - 1] != '1')
		keycode_0(movement, x, y);
	if (keycode == 13 && movement->map[y - 1][x] != '1')
		keycode_13(movement, x, y);
	if (keycode == 1 && movement->map[y + 1][x] != '1')
		keycode_1(movement, x, y);
	add_image(movement);
	return (0);
}
