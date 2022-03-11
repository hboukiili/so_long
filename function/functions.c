/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:39:32 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/11 00:08:44 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ptr = malloc (len + 1 * sizeof(char));
	i = 0;
	if (ptr == NULL)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	exit_mouse(int key)
{
	if (key < 0)
	{
		write (1, "EXIT\n", 5);
		exit(1);
	}
	return (0);
}

void	e_map(t_draw *p)
{
	mlx_put_image_to_window(p->mlx, p->wind, p->exit,
		p->height, p->width);
	p->e_x = p->x;
	p->e_n = p->n;
}

void	ft_pic_make2(t_draw *p)
{
	while (g_map[p->n][p->x])
	{
		mlx_put_image_to_window(p->mlx, p->wind, p->zero, p->height, p->width);
		if (g_map[p->n][p->x] == '1')
			mlx_put_image_to_window(p->mlx, p->wind, p->wall,
				p->height, p->width);
		else if (g_map[p->n][p->x] == 'P')
		{
			mlx_put_image_to_window(p->mlx, p->wind, p->player,
				p->height, p->width);
			p->p_x = p->x;
			p->p_n = p->n;
		}
		else if (g_map[p->n][p->x] == 'C')
			mlx_put_image_to_window(p->mlx, p->wind, p->coins,
				p->height, p->width);
		else if (g_map[p->n][p->x] == 'E')
			e_map(p);
		p->height += 50;
		p->x++;
	}
}
