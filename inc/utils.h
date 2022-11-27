/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:24:06 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/27 16:28:13 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "defines.h"

#ifndef UTILS_H
# define UTILS_H

void	terminate(char *s);
int		ft_destroy_window(t_vars *vars);
int		key_press(int keycode, t_all *all);
int		load_map(char *file_name, t_map *map);
void	draw_points(t_all *all, t_point *copy_points);
void	draw_map(t_all *all);
void	rotation_x(int total_size, t_point *points, t_point *projected, int ang);
void	rotation_y(int total_size, t_point *points, t_point *projected, int ang);
void	rotation_z(int total_size, t_point *points, t_point *projected, int ang);
void	map_init(t_map *map);
int		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	zoom(t_point *points, int len, float scale);
void	ft_reduce_z(int len, t_point *points, float divisor);
void	draw_map_line(t_all *all, int total_size, t_map *map, t_point *proyected);
int		ft_mouse_down(int mousecode, int x, int y, t_all *all);
int		ft_mouse_up(int mousecode, int x, int y, t_all *all);
int		ft_mouse_move(int x, int y, t_all *all);
void	angle(float *angle, float value);
#endif

