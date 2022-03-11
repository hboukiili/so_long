/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:48:16 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/11 00:51:55 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_back(t_draw *i)
{
	if (g_map[i->p_n + 1][i->p_x] != '1')
	{
		if (g_map[i->p_n + 1][i->p_x] != 'E')
		{
			mlx_put_image_to_window(i->mlx, i->wind, i->zero,
				i->p_x * 50, i->p_n * 50);
			i->p_n++;
			mlx_put_image_to_window(i->mlx, i->wind, i->player,
				i->p_x * 50, i->p_n * 50);
			if (g_map[i->p_n - 1][i->p_x] == 'C')
				g_map[i->p_n -1][i->p_x] = '0';
			if (g_map[i->p_n][i->p_x] == 'B')
			{	
				mlx_destroy_window(i->mlx, i->wind);
				free(i);
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
		}
	}
}

void	move_forward(t_draw *i)
{
	if (g_map[i->p_n - 1][i->p_x] != '1')
	{
		if (g_map[i->p_n - 1][i->p_x] != 'E')
		{
			mlx_put_image_to_window(i->mlx, i->wind, i->zero,
				i->p_x * 50, i->p_n * 50);
			i->p_n--;
			mlx_put_image_to_window(i->mlx, i->wind, i->player_b,
				i->p_x * 50, i->p_n * 50);
			if (g_map[i->p_n + 1][i->p_x] == 'C')
				g_map[i->p_n + 1][i->p_x] = '0';
			if (g_map[i->p_n][i->p_x] == 'B')
			{	
				mlx_destroy_window(i->mlx, i->wind);
				free(i);
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
		}
	}
}

void	move_right(t_draw *i)
{
	if (g_map[i->p_n][i->p_x + 1] != '1')
	{
		mlx_put_image_to_window(i->mlx, i->wind, i->zero,
			i->p_x * 50, i->p_n * 50);
		i->p_x++;
		mlx_put_image_to_window(i->mlx, i->wind, i->player_r,
			i->p_x * 50, i->p_n * 50);
		if (g_map[i->p_n][i->p_x - 1] == 'C')
			g_map[i->p_n][i->p_x - 1] = '0';
		if (g_map[i->p_n][i->p_x] == 'B')
		{	
			mlx_destroy_window(i->mlx, i->wind);
			free(i);
			write (1, "YOU WIN\n", 8);
			exit(1);
		}
	}
}

void	move_left(t_draw *i)
{
	if (g_map[i->p_n][i->p_x - 1] != '1')
	{
		mlx_put_image_to_window(i->mlx, i->wind, i->zero,
			i->p_x * 50, i->p_n * 50);
		i->p_x--;
		mlx_put_image_to_window(i->mlx, i->wind, i->player_l,
			i->p_x * 50, i->p_n * 50);
		if (g_map[i->p_n][i->p_x + 1] == 'C')
			g_map[i->p_n][i->p_x + 1] = '0';
		if (g_map[i->p_n][i->p_x] == 'B')
		{
			mlx_destroy_window(i->mlx, i->wind);
			free(i);
			write (1, "YOU WIN\n", 8);
			exit(1);
		}
	}
}

void	key_hook_2(int key, t_draw *i)
{
	if (key == 53)
	{
		mlx_destroy_window(i->mlx, i->wind);
		free(i);
		exit_mouse(-1);
	}
	if (!check_3(g_map, 'C'))
	{
		mlx_put_image_to_window(i->mlx, i->wind, i->exit_open,
			i->e_x * 50, i->e_n * 50);
		if (g_map[i->e_n][i->e_x] == 'E')
					g_map[i->e_n][i->e_x] = 'B';
	}
}
