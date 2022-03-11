/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:00:37 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/11 00:02:04 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_2(char **str)
{
	int	x;
	int	y;

	x = 0;
	while (str[x])
	{
		if (str[x][0] != '1' || str[x][ft_strlen(*str) - 1] != '1')
			error();
		x++;
	}
	y = 0;
	while (str[x - 1][y])
	{
		if (str[x - 1][y] != '1')
			error();
		y++;
	}
}

void	check_1(char **str)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			error();
		i++;
	}
	while (str[x])
	{
		if (i != ft_strlen(str[x]))
			error();
		x++;
	}
}

int	check_3(char **str, char c)
{
	int	x;
	int	i;
	int	y;

	x = 0;
	y = 0;
	while (str[x])
	{
		i = 0;
		while (str[x][i])
		{
			if (str[x][i] == c)
				y++;
			if ((str[x][i] == '1') || (str[x][i] == '0')
				|| (str[x][i] == 'C') || (str[x][i] == 'E')
					|| (str[x][i] == 'P'))
				i++;
			else
				return (0);
		}
		x++;
	}
	return (y);
}

void	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	if (str[i + 1] != 'b')
		error();
	if (str[i + 2] != 'e')
		error();
	if (str[i + 3] != 'r')
		error();
	if (str[i + 4])
		error();
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
