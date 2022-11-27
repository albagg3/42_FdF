/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:19:15 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/27 16:28:27 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <stdio.h>


int		ft_mouse_down(int mousecode,int x, int y, t_all *all)
{
	if(mousecode == 1)
	{
		printf("entra_en_mouse_down");
		all->mouse.left_click = 1;
		all->mouse.prev_click_l.coordinates[X] = x;
		all->mouse.prev_click_l.coordinates[Y] = y;
	}
	if(mousecode == 3)
	{
		all->mouse.wheel_click = 1;
		all->mouse.prev_click_w.coordinates[X] = x;
		all->mouse.prev_click_w.coordinates[Y] = y;

	}
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

int		ft_mouse_move(int x, int y, t_all *all)
{
	if(all->mouse.wheel_click)
	{
		printf("angX: %f\n angY: %f\n",	all->map.ang[X], all->map.ang[Y]);
		angle(&all->map.ang[X], all->mouse.prev_click_l.coordinates[Y] - y);
		angle(&all->map.ang[Y], all->mouse.prev_click_l.coordinates[X] - x);
		all->mouse.prev_click_l.coordinates[X] = x;
		all->mouse.prev_click_l.coordinates[Y] = y;
		draw_map(all);
	}
/*	if(all->mouse.left_click)
	{
		printf("entra aqui");
		all->map.points.coordinates = all->mouse.prev_click_l.coordinates[Y] - y;
		all->map.ang[Y] = all->mouse.prev_click_l.coordinates[X] - x;
		all->mouse.prev_click_l.coordinates[Y] = x;
		all->mouse.prev_click_l.coordinates[Y] = y;
	}*/
	

	return(0);
}

int		ft_mouse_up(int mousecode,int x, int y, t_all *all)
{
	x++;
	y++;
	if(mousecode == 1)
		all->mouse.left_click = 0;
	if(mousecode == 3)
		all->mouse.wheel_click = 0;
	return(0);
}
