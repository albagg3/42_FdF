/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:08:59 by albagarc          #+#    #+#             */
/*   Updated: 2022/11/24 16:54:31 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#ifndef DEFINES_H
# define DEFINES_H
# define ROJO 		0xc1272d
# define BLACK		0x000000

# define WINX 1920
# define WINY 1080

# define BUFFER_SIZE 10
# define X 0
# define Y 1
# define Z 2

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_point {
	float	coordinates[3];
	int		color;
}	t_point;

typedef struct s_map {
	t_point		*points; //guardamos los puntos originales
	t_point		limits; //guardamos los limites del mapa en la x en la y y en la z 
	
	float		ang[3];
	float		divisor;
	int			len;
	float		scale;
	int			total_size; // total de puntos del mapa

}	t_map;

typedef struct s_mouse {
	bool	left_click;
	bool	wheel_click;
	bool	right_click;
	t_point prev_click_l;
	t_point prev_click_w;
}	t_mouse;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_all {
	t_vars	vars;
	t_map	map;
	t_data	data;
	t_mouse mouse;
}			t_all;


#endif                
