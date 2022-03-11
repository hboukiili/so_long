/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:22:25 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/11 00:19:48 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_g_map(char *str)
{
	int		fd;
	char	*s;
	char	*new;
	char	**splt;

	fd = open(str, O_RDONLY);
	s = get_next_line(fd);
	if (s == NULL)
		error();
	new = ft_strdup("");
	while (s)
	{
		new = ft_strjoin(new, s);
		free(s);
		s = get_next_line(fd);
	}
	splt = ft_split(new, '\n');
	free(new);
	return (splt);
}

int	key_hook(int key, t_draw *i)
{
	static int	m;

	if (key == 125 || key == 1)
	{
		move_back(i);
		m++;
	}
	else if (key == 126 || key == 13)
	{
		move_forward(i);
		m++;
	}
	else if (key == 124 || key == 2)
	{
		move_right(i);
		m++;
	}
	else if (key == 123 || key == 0)
	{
		move_left(i);
		m++;
	}
	ft_printf("%d\n", m);
	key_hook_2(key, i);
	return (0);
}

void	ft_pic_make(t_draw *p, int h, int w)
{
	p->wall = mlx_xpm_file_to_image(p->mlx, "./xpm/1.xpm", &w, &h);
	p->player_b = mlx_xpm_file_to_image(p->mlx, "./xpm/P_B.xpm", &w, &h);
	p->player_l = mlx_xpm_file_to_image(p->mlx, "./xpm/P_L.xpm", &w, &h);
	p->player_r = mlx_xpm_file_to_image(p->mlx, "./xpm/P_R.xpm", &w, &h);
	p->exit_open = mlx_xpm_file_to_image(p->mlx, "./xpm/E_O.xpm", &h, &w);
	p->x = 0;
	p->n = 0;
	while (g_map[p->n])
	{
		p->x = 0;
		p->height = 0;
		ft_pic_make2(p);
		p->width += 50;
		p->n++;
	}
	mlx_key_hook(p->wind, key_hook, p);
	mlx_hook(p->wind, 17, 1L << 0, exit_mouse, &p);
	mlx_loop(p->mlx);
}

void	paint(char **g_map)
{
	t_draw	*p;
	int		h;
	int		w;
	int		x;
	int		n;

	n = 0;
	x = ft_strlen(*g_map);
	p = malloc(sizeof(t_draw) * 1);
	while (g_map[n])
		n++;
	p->height = 0;
	p->width = 0;
	p->mlx = mlx_init();
	p->wind = mlx_new_window(p->mlx, x * 50, n * 50, "lol");
	p->player = mlx_xpm_file_to_image(p->mlx, "./xpm/P_F.xpm", &w, &h);
	p->coins = mlx_xpm_file_to_image(p->mlx, "./xpm/C.xpm", &w, &h);
	p->exit = mlx_xpm_file_to_image(p->mlx, "./xpm/E_C.xpm", &w, &h);
	p->zero = mlx_xpm_file_to_image(p->mlx, "./xpm/0.xpm", &w, &h);
	ft_pic_make(p, h, w);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		check_name(av[1]);
		g_map = read_g_map(av[1]);
		check_1(g_map);
		check_2(g_map);
		if ((!check_3(g_map, 'C')) || (check_3(g_map, 'P') != 1)
			|| (!check_3(g_map, 'E')))
			error();
		paint(g_map);
	}
}
