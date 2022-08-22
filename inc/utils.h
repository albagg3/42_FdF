/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:24:06 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/21 14:14:38 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "defines.h"

#ifndef UTILS_H
# define UTILS_H

void	terminate(char *s);
int	key_press(int keycode, t_vars *vars);
int	load_map(char *file_name, t_map *map);
int 	draw_points(t_all *all);
#endif

