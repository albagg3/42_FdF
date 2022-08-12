/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:29:30 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/12 14:38:38 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "../lib/libft_src/libft.h"

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
//		printf("line:%s\n", line);
		line = get_next_line(fd);
		map->total_size += max_x;
//		printf("split:%c\n", splitted[2][0]);
		map->limits.coordinates[Y]++;
	}
//	printf("max_x:%d\n", max_x);
//	printf("map->limits.coordinates[X]:%i\n", map->limits.coordinates[X]);
//	printf("totalsize:%i\n", map->total_size);
//	printf("fuerasplit:%c\n", splitted[2][2]);
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
		map->points[map->total_size].coordinates[X] = i;
		map->points[map->total_size].coordinates[Y] = line_number;
		map->points[map->total_size].coordinates[Z] = ft_atoi(splitted[i]);
		i++;
		printf("[X]=%d\n", map->points[map->total_size].coordinates[X]);
		printf("[Y]=%d\n", map->points[map->total_size].coordinates[Y]);
		printf("[Z]=%d\n", map->points[map->total_size].coordinates[Z]);
	}
	map->total_size++;
}

int load_map(char *file_name, t_map *map)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number=0;
	valid_map(file_name, map);
	map->points = ft_calloc (map->total_size, sizeof(t_point));
	if (map->points == NULL)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		return(0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_map_points(map,line_number, line); 
		line_number++;
		line = get_next_line(fd);
		printf("line_number:%d\n", line_number);
	}
	return(1);
}

int main (int argc, char **argv)
{
	t_map	map;

	if(argc != 2)
		return (0);
	
	load_map(argv[1], &map);
//	printf("[X]=%c\n", map.points[map.total_size].coordinates[X]);
//	valid_map(argv[1], &map);
	printf("fd=%d", valid_map(argv[1], &map));

}
