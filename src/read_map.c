/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:29:30 by albagarc          #+#    #+#             */
/*   Updated: 2022/12/01 11:44:05 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include "../lib/libft_src/libft.h"
#include "../lib/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/errors.h"

//Contamos los elementos de cada linea, con este dato podremos ir comparandolo
// y sabiendo si todas las lineas tienen el mismo numero de elementos para que
//pueda ser un mapa valido.

int	count_elems_line(char **split)
{
	int	i;

	i = 0;
	while (split[i] && split[i][0] != '\n')
		i++;
	if (i == 0 || (i == 1 && split[i][0] == '\n'))
		terminate(ERR_EMPTY);
	return (i);
}

//Con esta funcion vamos recorriendo el mapa y guardamos los maximos y 
//comprobamos si el mapa es valido. para poder contar los elementos hacemos 
//el split y nos quita los espacios y tenemos cada valor en un array.

void	valid_map(char	*file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**splitted;
	int		max_x;

	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		terminate(ERR_NOMAP);
	line = get_next_line(fd);
	while (line != NULL)
	{
		splitted = ft_split(line, ' ');
		max_x = count_elems_line(splitted);
		if (map->limits.coord[X] == 0)
			map->limits.coord[X] = max_x;
		if (map->limits.coord[X] != max_x)
			terminate(ERR_MAP);
		free(line);
		free_double_pointer(splitted);
		line = get_next_line(fd);
		map->total_size += max_x;
		map->limits.coord[Y]++;
		write(1, "*", 1);
	}
	close(fd);
}

void	ft_load_color(t_map *map, char *line)
{
	char	**color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		map->points[map->len].color = (long)strtol(color[1] + 2, NULL, 16);
		free_double_pointer(color);
	}
	else
		map->points[map->len].color = 0xFFFF00;
}

//Funcion que me guarde los valores de los puntos en arrays

void	save_map_points(t_map *map, int line_number, char *line)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(line, ' ');
	while (splitted[i] && splitted[i][0] != '\n')
	{
		map->points[map->len].coord[X] = i - map->limits.coord[X] / 2;
		map->points[map->len].coord[Y] = line_number - map->limits.coord[Y] / 2;
		if (!ft_isdigit(splitted[i][0]))
			terminate(ERR_MAP);
		map->points[map->len].coord[Z] = ft_atoi(splitted[i]);
		ft_load_color(map, splitted[i]);
		i++;
		map->len++;
	}
	free_double_pointer(splitted);
}

//funcion que junto con la anterior me guarda en un array todos 
//los valores de los puntos.

int	load_map(char *file_name, t_map *map)
{
	int		line_number;
	int		fd;
	char	*line;

	line_number = 0;
	map_init(map);
	valid_map(file_name, map);
	map->points = ft_calloc (map->total_size, sizeof(t_point));
	if (map->limits.coord[X] == 0)
		terminate(ERR_EMPTY);
	fd = open(file_name, O_RDONLY);
	if (fd < 2 || map->points == NULL)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_map_points(map, line_number, line);
		line_number++;
		free(line);
		line = get_next_line(fd);
		write(1, ".", 1);
	}
	return (1);
}
