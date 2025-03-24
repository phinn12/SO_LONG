/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:46:39 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/28 18:28:24 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		write(1, s, i);
	}
	else
		i += write(1, "(null)", 6);
	return (i);
}

int	ft_putptr(void *p)
{
	unsigned long	adr;
	int				i;

	i = 0;
	adr = (unsigned long)p;
	if (adr > 15)
		i += ft_putptr((void *)(adr / 16));
	i += write(1, &"0123456789abcdef"[adr % 16], 1);
	return (i);
}

int	ft_putnbr(long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i += write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
		i += ft_putnbr(num / 10);
	i += write(1, &"0123456789"[num % 10], 1);
	return (i);
}

int	ft_puthex(unsigned int num, char c)
{
	int	i;

	i = 0;
	if (num > 15)
		i += ft_puthex(num / 16, c);
	if (c == 'x')
		i += write(1, &"0123456789abcdef"[num % 16], 1);
	else
		i += write(1, &"0123456789ABCDEF"[num % 16], 1);
	return (i);
}
