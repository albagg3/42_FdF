/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:19:15 by albagarc          #+#    #+#             */
/*   Updated: 2022/10/22 11:54:18 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"

int		ft_mouse_down(int mousecode,int x, int y, t_all *all)
{
	x = 0;
	y = 0;
	if (mousecode == 4)
	{
		all->map.scale *= 1.5;
	}
	if (mousecode == 5)
	{
		all->map.scale /= 1.5;
	}
	if (mousecode == 3)
	{

	}
	draw_map(all);
	return (0);
}


/*int		ft_mouse_up(int mousecode,int x, int y, t_all *all)
{
	
}


int		ft_mouse_move(int mousecode,int x, int y, t_all *all)
{

}*/

