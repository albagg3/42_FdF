/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:29:30 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/11 20:06:49 by albagarc         ###   ########.fr       */
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
/*	int i;

	i = 0;
	while (split[i] && split[i][1] != '\n')
	{
		i++;
	}
	return (i);*/
}

//Con esta funcion vamos recorriendo el mapa y guardamos 

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
		printf("line:%s\n", line);
		line = get_next_line(fd);
		map->total_size += max_x;
		printf("split:%c\n", splitted[2][3]);
		map->limits.coordinates[Y]++;
	}
	printf("max_x:%d\n", max_x);
	printf("map->limits.coordinates[X]:%i\n", map->limits.coordinates[X]);
	printf("totalsize:%i\n", map->total_size);
	printf("fuerasplit:%c\n", splitted[2][200]);
	printf("map->limits.coordinates[Y]:%i\n", map->limits.coordinates[Y]);

	return(fd);

}



int main (int argc, char **argv)
{
	t_map	map;
	if(argc != 2)
		return (0);
	
//	valid_map(argv[1], &map);
	printf("fd=%d", valid_map(argv[1], &map));

}
