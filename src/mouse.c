/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:19:15 by albagarc          #+#    #+#             */
/*   Updated: 2022/10/15 12:59:23 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"

int		ft_mouse_down(int mousecode,int x, int y, t_all *all)
{
	x = 0;
	y = 0;
	if( mousecode == 4)
	{
		all->map.scale *= 1.5;
	}
	if( mousecode == 5)
	{
		all->map.scale /= 1.5;
	}
	draw_map(all);
	return (0);
}
