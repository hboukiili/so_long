/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 03:22:48 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/11 22:34:35 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

char	**g_map;
typedef struct draw {
	void	*mlx;
	void	*wind;
	void	*wall;
	void	*player;
	void	*zero;
	void	*coins;
	void	*exit;
	int		width;
	int		height;
	void	*player_l;
	void	*player_r;
	void	*player_b;
	void	*exit_open;
	void	*win;
	int		x;
	int		n;
	int		p_x;
	int		p_n;
	int		e_x;
	int		e_n;
}	t_draw;
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchr(char *s);
int		ft_strlen(char *str);
char	*ft_check(char *a);
char	*ft_print(char *a);
char	*get_len(int fd, char *a);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
void	check_name(char *str);
int		check_3(char **str, char c);
void	check_1(char **str);
void	check_2(char **str);
void	error(void);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printf(const char *s, ...);
int		ft_putnbr2(unsigned int n);
int		ft_putnbr(int nb);
int		ft_printhexaup(unsigned int nb);
int		ft_printhexalow(unsigned int nb);
int		ft_adress(unsigned long nb);
int		len(int long nb);
int		len2(unsigned long nb);
int		ft_print_adress(unsigned long nb);
int		ft_printf(const char *s, ...);
int		exit_mouse(int key);
int		move_back(t_draw *i, int m);
int		move_forward(t_draw *i, int m);
int		move_right(t_draw *i, int m);
int		move_left(t_draw *i, int m);
void	key_hook_2(int key, t_draw *i);
void	ft_pic_make2(t_draw *p);

#endif