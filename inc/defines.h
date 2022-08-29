/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:08:59 by albagarc          #+#    #+#             */
/*   Updated: 2022/08/29 09:03:00 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# define ROJO 		0xc1272d

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
	int		coordinates[3];
	int		color;
}	t_point;

typedef struct s_map {
	t_point		*points;
	t_point		limits;
	t_point		*projected;
	int			len;
	int			total_size;

}	t_map;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_all {
	t_vars	vars;
	t_map	map;
	t_data	data;
}			t_all;


#endif                
