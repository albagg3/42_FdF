/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:46:51 by albagarc          #+#    #+#             */
/*   Updated: 2022/10/08 12:28:19 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/utils.h"
#include <math.h>
int	draw_line(t_all *all, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

//	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
//		return (0);
	delta.coordinates[X] = end.coordinates[X] - start.coordinates[X];
	delta.coordinates[Y] = end.coordinates[Y] - start.coordinates[Y];
	pixels = sqrt((delta.coordinates[X] * delta.coordinates[X]) + \
			(delta.coordinates[Y] * delta.coordinates[Y]));
	len = pixels;
	delta.coordinates[X] /= pixels;
	delta.coordinates[Y] /= pixels;
	pixel.coordinates[X] = start.coordinates[X];
	pixel.coordinates[Y] = start.coordinates[Y];
	while (pixels > 0)
	{
//		pixel.color = gradient(start.color, end.color, len, len - pixels);
//		my_putpixel(meta, pixel);  //Func Ai
		my_mlx_pixel_put(&all->data, pixel.coordinates[X] + WINX / 2, pixel.coordinates[Y] + WINY/2, 0xff0000);
		pixel.coordinates[X] += delta.coordinates[X];
		pixel.coordinates[Y] += delta.coordinates[Y];
		pixels = pixels - 1;
	}
	return (1);
}

void	draw_map_line (t_all *all, int total_size, t_map *map, t_point *proyected)
{
	int i;
	
	i = 0;
	while( i < total_size)
	{
		if(i % (int)map->limits.coordinates[X] != 0 || i == 0)
		{
			draw_line(all, proyected[i], proyected[i + 1]);
			draw_line(all, proyected[i], proyected[(i) + (int)map->limits.coordinates[X]]);	//DIBUJA LAS LINEAS HORIZONTAL Y VERTICAL
		}
	//	else if(i == (int)map->limits.coordinates[Y])
	//		draw_line(all, proyected[i], proyected[i + 1]); 				//SOLO DIBUJA LAS LINEAS HORIZONTALES DE ABAJO
	//	else
	//		draw_line(all, proyected[i], proyected[(i + 1) * (int)map->limits.coordinates[X]]); 	//SOLO DIBUJA LAS VERTICALES FINAL DE LINEA	
		i++;
	}
}



