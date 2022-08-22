/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:29:30 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/22 12:06:23 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft_src/libft.h"
#include "../lib/minilibx_macos/mlx.h"

//Contamos los elementos de cada linea, con este dato podremos ir comparandolo y sabiendo si todas las lineas tienen el mismo numero de elementos para que pueda ser un mapa valido.

int count_elems_line(char **split)
{
	int		i;

	i = 0;
	while (split[i] && split[i][0] != '\n')
		i++;
	return (i);
}

//Con esta funcion vamos recorriendo el mapa y guardamos los maximos y comprobamos si el mapa es valido. para poder contar los elementos hacemos el split y nos quita los espacios y tenemos cada valor en un array. 
int	valid_map(char	*file_name, t_map *map)
{
	int		fd; 
	char	*line;
	char 	**splitted;
	int 	max_x;

	map->total_size = 0;
	map->limits.coordinates[X] = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		splitted = ft_split(line, ' ');
		max_x = count_elems_line(splitted);
		if (map->limits.coordinates[X] == 0)
			map->limits.coordinates[X] = max_x;
		if (map->limits.coordinates[X] != max_x)
			return(0);
		line = get_next_line(fd);
		map->total_size += max_x;
		map->limits.coordinates[Y]++;
		
	}
	printf("max_x:%d\n", max_x);
//	printf("map->limits.coordinates[X]:%i\n", map->limits.coordinates[X]);
	printf("TOTALSIZE:%d\n", map->total_size);

//	printf("map->limits.coordinates[Y]:%i\n", map->limits.coordinates[Y]);
	close(fd);
	return(1);

}

//Funcion que me guarde los valores de los puntos en arrays
void	save_map_points(t_map *map, int	line_number, char *line)
{
	int i;
	char **splitted;

	i = 0;
	splitted = ft_split(line, ' ');
	
	while (splitted[i] && splitted[i][0] != '\n')
	{
		printf("i:%d\n", i);
		map->points[map->len].coordinates[X] = i;
		map->points[map->len].coordinates[Y] = line_number;
		map->points[map->len].coordinates[Z] = ft_atoi(splitted[i]);
		i++;
		printf("[X]=%d\n", map->points[map->len].coordinates[X]);
		printf("[Y]=%d\n", map->points[map->len].coordinates[Y]);
		printf("[Z]=%d\n", map->points[map->len].coordinates[Z]);
	}
	map->len++;
	printf("i en save-map:%d\n", i);

	printf("total_size en save_map:%d\n", map->total_size);
}
//funcion que junto con la anterior me guarda en un array todos los valores de los puntos.

int load_map(char *file_name, t_map *map)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number=0;
	
	valid_map(file_name, map);
	printf("TOT=%d\n", map->total_size);
	map->points = ft_calloc (map->total_size, sizeof(t_point));
	if (map->points == NULL)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		return(0);
	line = get_next_line(fd);
	map->len = 0;
	while (line != NULL)
	{
		save_map_points(map,line_number, line); 
		line_number++;
		line = get_next_line(fd);
		printf("line_number:%d\n", line_number);
	}
	return(1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_points(t_all *all)
{
	int i;
	i = 0;
//	while( i< 1920)
//		{
//			my_mlx_pixel_put(&all->data, i, i/4, ROJO);
//			i++;
//		}
	
	while (i < all->map.total_size)
	{
		printf("VALORES EN DRAW x= %d\n",all->map.points[i].coordinates[X]);
		printf("VALORES EN DRAW y= %d\n",all->map.points[i].coordinates[Y]);
		my_mlx_pixel_put(&all->data,all->map.points[i].coordinates[X]*10, all->map.points[i].coordinates[Y]*10, 0xff0000);
		i++;
	}

}

