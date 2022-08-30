/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:24:06 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/30 10:40:31 by albagarc         ###   ########.fr       */
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
void	rotation_x(int total_size, t_point *points, t_point *pprojected, int ang);
void    map_init(t_map *map);
#endif

