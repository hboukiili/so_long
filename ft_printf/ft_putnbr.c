/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:46:54 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/10 22:39:16 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putnbr(int nb)
{
	unsigned int	n;
	unsigned int	x;

	n = 0;
	x = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * -1;
		x++;
	}
	else
		n = nb;
	if (n >= 10)
	{
		x += ft_putnbr(n / 10);
		x += ft_putchar((n % 10) + 48);
	}
	if (n < 10)
		x += ft_putchar(n + 48);
	return (x);
}
